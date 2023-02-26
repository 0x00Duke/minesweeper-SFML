/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Server.cpp
*/

#include "../include/Server.hpp"

eecsge::Coordinator gCoordinator;

Server::Server()
{
    gCoordinator.Init();
    mapSystem = gCoordinator.RegisterSystem<MapSystem>();

    initSignatures();
}

Server::~Server()
{
}

void Server::run()
{
    srand(time(0));

    initTiles();

    RevealTileListener revealTileListener;
    revealTileListener.init(mapSystem);

    while (true) {
        mapSystem->update();
    }
}
