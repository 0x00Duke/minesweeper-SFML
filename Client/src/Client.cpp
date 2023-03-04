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

    initSignatures();

    logl("Client Started");
}

Client::~Client()
{
}

void Client::ReceivePackets(sf::TcpSocket *socket)
{
    while (true) {
        if (socket->receive(last_packet) == sf::Socket::Done) {
            std::string received_string;
            std::string sender_address;
            unsigned short sender_port;
            last_packet >> received_string >> sender_address >> sender_port;
            logl("From (" << sender_address << ":" << sender_port << "): " << received_string);
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
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Minesweeper");

    Lobby lobby(&window, &socket);
    lobby.connectionLobby();

    // create the background
    initBackground();
    // create the tiles
    initTiles();
    // create the miner
    initMiner();

    ClickListener clickListener;
    clickListener.init();

    RevealTileListener revealTileListener;
    revealTileListener.init(mapSystem);

    // int x = 1;
    // int y = 1;
    // int value = 0;

    std::thread reception_thred(&Client::ReceivePackets, this, &socket);

    sf::Event event; 
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            // if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                // Event newEvent(Events::RevealTile::REVEAL);
                // newEvent.SetParam(Events::RevealTile::Reveal::X, x);
                // newEvent.SetParam(Events::RevealTile::Reveal::Y, y);
                // newEvent.SetParam(Events::RevealTile::Reveal::VALUE, 1);
                // gCoordinator.SendEvent(newEvent);
                // if (x == 10) {
                    // x = 1;
                    // y++;
                // } else {
                    // x++;
                // }
            // } else {
                minerSystem->update(event);
            // }
        }

        window.clear();
        backgroundSystem->update();
        mapSystem->update();
        drawSystem->DrawEntities(&window);
        window.display();

        std::string user_input;
        std::getline(std::cin, user_input);
        
        if (user_input.length() < 1)
            continue;
        
        sf::Packet reply_packet;
        reply_packet << user_input;
        
        SendPacket(reply_packet);
    }
}
