/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** game.cpp
*/

#include "../include/game.hpp"
#include "../include/systems/miner.hpp"
#include "../include/systems/background.hpp"
#include "../include/systems/map.hpp"
#include "../include/systems/winLoose.hpp"
#include "../include/components/tile.hpp"
#include "../include/init.hpp"
#include <time.h>

Coordinator gCoordinator;

Game::Game()
{
    gCoordinator.Init();
}

Game::~Game()
{
}

void Game::run()
{

    srand(time(0));

    auto minerSystem = gCoordinator.RegisterSystem<MinerSystem>();
    auto drawSystem = gCoordinator.RegisterSystem<DrawSystem>();
    auto movementSystem = gCoordinator.RegisterSystem<MovementSystem>();
    auto backgroundSystem = gCoordinator.RegisterSystem<newBackgroundSystem>();
    auto mapSystem = gCoordinator.RegisterSystem<MapSystem>();
    auto winLooseSystem = gCoordinator.RegisterSystem<WinLooseSystem>();


    // create the window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Minesweeper");

    initSignatures();
    // create the background
    initBackground();
    // create the map
    initMap();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        window.clear();
        // playerSystem->update(event);
        // movementSystem->update(event);
        backgroundSystem->update(event);
        mapSystem->update(event, &window);
        drawSystem->DrawEntities(&window);

        window.display();

        winLooseSystem->update(event, &window);
    }
}
