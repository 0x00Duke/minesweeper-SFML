/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Server.cpp
*/

#include "../include/Server.hpp"

eecsge::Coordinator gCoordinator;

Server::Server(unsigned short port) : listen_port(port)
{
    std::cout << "Server started on port " << listen_port << std::endl;

    if (listener.listen(listen_port) != sf::Socket::Done) {
        logl("Could not listen");
    }

    gCoordinator.Init();
    mapSystem = gCoordinator.RegisterSystem<MapSystem>();
    clientsSystem = gCoordinator.RegisterSystem<ClientsSystem>();
    winLooseSystem = gCoordinator.RegisterSystem<WinLooseSystem>();

    initSignatures();
}

Server::~Server()
{
}

void Server::ConnectClients()
{
    while (isRunning) {
        sf::TcpSocket *new_client = new sf::TcpSocket();
        if (listener.accept(*new_client) == sf::Socket::Done) {
            new_client->setBlocking(false);

            // create a new entity for the client
            eecsge::Entity client = gCoordinator.CreateEntity();
            gCoordinator.AddComponent(client, Client{new_client});

            logl("Added client " << new_client->getRemoteAddress() << ":" << new_client->getRemotePort());
        }
        else if (isRunning){
            logl("Server listener error, restart the server");
            delete (new_client);
            break;
        }
    }
}

void Server::run()
{
    std::thread connetion_thread(&Server::ConnectClients, this);
    srand(time(0));

    initTiles();

    RevealTileListener revealTileListener;
    revealTileListener.init(mapSystem);

    SendTileListener sendTileListener;
    sendTileListener.init(clientsSystem);

    EndGameListener endGameListener;
    endGameListener.init(clientsSystem);

    while (true) {
        mapSystem->update();
        clientsSystem->update();
        if (winLooseSystem->check()) {
            isRunning = false;
            break;
        }

        std::this_thread::sleep_for((std::chrono::milliseconds)250);
    }
    connetion_thread.detach();
}
