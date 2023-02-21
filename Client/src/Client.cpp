/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** client.cpp
*/

#include "../include/Client.hpp"

Coordinator gCoordinator;

Client::Client()
{
    gCoordinator.Init();
    drawSystem = gCoordinator.RegisterSystem<DrawSystem>();
    movementSystem = gCoordinator.RegisterSystem<MovementSystem>();
    backgroundSystem = gCoordinator.RegisterSystem<newBackgroundSystem>();
    minerSystem = gCoordinator.RegisterSystem<MinerSystem>();
    // mapSystem = gCoordinator.RegisterSystem<MapSystem>();

    initSignatures();
}

Client::~Client()
{
}

void Client::run()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Minesweeper");

    // create the background
    initBackground();
    // create the tiles
    initTiles();
    // create the miner
    initMiner();

    ClickListener clickListener;
    clickListener.init();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        backgroundSystem->update(event);
        minerSystem->update(event);
        drawSystem->DrawEntities(&window);
        window.display();
    }
}