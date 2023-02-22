/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** RevealTile.cpp
*/

#include "../../include/listeners/RevealTile.hpp"

extern Coordinator gCoordinator;

void RevealTileListener::init(std::shared_ptr<MapSystem> mapSystem)
{
    _mapSystem = mapSystem;
    gCoordinator.AddListener(METHOD_LISTENER(Events::RevealTile::REVEAL, RevealTileListener::callMapSystem));
}

void RevealTileListener::callMapSystem(Event &event)
{
    _mapSystem->revealTile(event);
}
