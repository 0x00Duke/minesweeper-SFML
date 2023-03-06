/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** client.cpp
*/

#include "../include/Client.hpp"

eecsge::Coordinator gCoordinator;

Client::Client()
{
    gCoordinator.Init();
    drawSystem = gCoordinator.RegisterSystem<eecsge::DrawSystem>();
    backgroundSystem = gCoordinator.RegisterSystem<newBackgroundSystem>();
    minerSystem = gCoordinator.RegisterSystem<MinerSystem>();
    mapSystem = gCoordinator.RegisterSystem<MapSystem>();
    textSystem = gCoordinator.RegisterSystem<TextSystem>();

    initSignatures();

    logl("Client Started");
}

Client::~Client()
{
}

void Client::emitRevealTileEvent(std::string tile)
{
}

void Client::proccessPacket(std::string message)
{
    std::string action = message.substr(0, message.find(";"));

    if (action == "reveal") {

        std::string x = message.substr(message.find(";") + 1, message.length());
        std::string y = x.substr(x.find(";") + 1, x.length());
        std::string value = y.substr(y.find(";") + 1, y.length());
        
        eecsge::Event newEvent(Events::RevealTile::REVEAL);
        newEvent.SetParam(Events::RevealTile::Reveal::X, std::stoi(x));
        newEvent.SetParam(Events::RevealTile::Reveal::Y, std::stoi(y));
        newEvent.SetParam(Events::RevealTile::Reveal::VALUE, std::stoi(value));
        gCoordinator.SendEvent(newEvent);
    }

    if (action == "endGame") {
        std::string status = message.substr(message.find(";") + 1, message.length());
        eecsge::Event newEvent(Events::EndGame::ENDGAME);
        newEvent.SetParam(Events::EndGame::EndGame::status, status);
        gCoordinator.SendEvent(newEvent);
    }
}

void Client::ReceivePackets(sf::TcpSocket *socket)
{
    while (true) {
        if (socket->receive(last_packet) == sf::Socket::Done) {
            std::string received_string;
            std::string sender_address;
            unsigned short sender_port;
            last_packet >> received_string >> sender_address >> sender_port;
            proccessPacket(received_string);
        }
        std::this_thread::sleep_for((std::chrono::milliseconds)250);
    }
}

void Client::SendPacket(sf::Packet &packet)
{
    if (packet.getDataSize() > 0 && socket.send(packet) != sf::Socket::Done) {
        logl("Could not send packet");
    }
}

void Client::run()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Minesweeper", sf::Style::Titlebar | sf::Style::Close);

    Lobby lobby(&window, &socket);
    int lobbyStatus = lobby.connectionLobby();
    if (lobbyStatus) {
        if (lobbyStatus == -1)
            window.close();
        return;
    }

    if (initBackground() || initTiles())
        return;
    // create the miner
    initMiner();

    ClickListener clickListener;
    clickListener.init(&socket);

    RevealTileListener revealTileListener;
    revealTileListener.init(mapSystem);

    EndGameListener endGameListener;
    endGameListener.init(&window);

    std::thread reception_thred(&Client::ReceivePackets, this, &socket);

    sf::Event event; 
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                socket.disconnect();
                reception_thred.detach();
                window.close();
                return;
            }
            minerSystem->update(event);
        }

        window.clear();
        backgroundSystem->update();
        mapSystem->update();
        drawSystem->DrawEntities(&window);
        textSystem->update(&window);
        window.display();
    }
}
