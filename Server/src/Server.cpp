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

    initSignatures();
}

Server::~Server()
{
}

void Server::ConnectClients(std::vector<sf::TcpSocket *> *client_array)
{
    while (true) {
        sf::TcpSocket *new_client = new sf::TcpSocket();
        if (listener.accept(*new_client) == sf::Socket::Done) {
            new_client->setBlocking(false);
            client_array->push_back(new_client);
            logl("Added client " << new_client->getRemoteAddress() << ":" << new_client->getRemotePort() << " on slot " << client_array->size());
        }
        else {
            logl("Server listener error, restart the server");
            delete (new_client);
            break;
        }
    }
}

void Server::DisconnectClient(sf::TcpSocket *socket_pointer, size_t position)
{
    logl("Client " << socket_pointer->getRemoteAddress() << ":" << socket_pointer->getRemotePort() << " disconnected, removing");
    socket_pointer->disconnect();
    delete (socket_pointer);
    client_array.erase(client_array.begin() + position);
}

void Server::BroadcastPacket(sf::Packet &packet, sf::IpAddress exclude_address, unsigned short port)
{
    for (size_t iterator = 0; iterator < client_array.size(); iterator++) {
        sf::TcpSocket *client = client_array[iterator];
        if (client->getRemoteAddress() != exclude_address || client->getRemotePort() != port) {
            if (client->send(packet) != sf::Socket::Done) {
                logl("Could not send packet on broadcast");
            }
        }
    }
}

void Server::ReceivePacket(sf::TcpSocket *client, size_t iterator)
{
    sf::Packet packet;
    if (client->receive(packet) == sf::Socket::Disconnected) {
        DisconnectClient(client, iterator);
        return;
    }

    if (packet.getDataSize() > 0) {
        std::string received_message;
        packet >> received_message;
        packet.clear();

        packet << received_message << client->getRemoteAddress().toString() << client->getRemotePort();

        BroadcastPacket(packet, client->getRemoteAddress(), client->getRemotePort());
        logl(client->getRemoteAddress().toString() << ":" << client->getRemotePort() << " '" << received_message << "'");
    }
}

void Server::ManagePackets()
{
    while (true) {
        for (size_t iterator = 0; iterator < client_array.size(); iterator++) {
            ReceivePacket(client_array[iterator], iterator);
        }
        std::this_thread::sleep_for((std::chrono::milliseconds)250);
    }
}

void Server::run()
{
    std::thread connetion_thread(&Server::ConnectClients, this, &client_array);
    ManagePackets();
    srand(time(0));

    initTiles();

    RevealTileListener revealTileListener;
    revealTileListener.init(mapSystem);

    while (true) {
        mapSystem->update();

        for (size_t iterator = 0; iterator < client_array.size(); iterator++) {
            ReceivePacket(client_array[iterator], iterator);
        }

        std::this_thread::sleep_for((std::chrono::milliseconds)250);
    }
    connetion_thread.join();
}
