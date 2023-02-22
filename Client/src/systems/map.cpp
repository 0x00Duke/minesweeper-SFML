/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** map.cpp
*/

#include "../../include/systems/map.hpp"

extern Coordinator gCoordinator;

void MapSystem::update()
{
    for (auto entity : mEntities) {
        auto &tile = gCoordinator.GetComponent<Tile>(entity);
        auto &drawable = gCoordinator.GetComponent<Drawable>(entity);

        if (tile.x == x && tile.y == y) {
            tile.value = value;
            drawable.rect = sf::IntRect(tile.value * 32, 0, 32, 32);
            x = -1;
            y = -1;
            value = 0;
        }
    }
}

void MapSystem::revealTile(Event &event)
{
    x = event.GetParam<int>(Events::RevealTile::Reveal::X);
    y = event.GetParam<int>(Events::RevealTile::Reveal::Y);
    value = event.GetParam<int>(Events::RevealTile::Reveal::VALUE);
}
