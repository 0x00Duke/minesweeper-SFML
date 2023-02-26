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
}

Client::~Client()
{
}

void Client::run()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Minesweeper");

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
    }
}
