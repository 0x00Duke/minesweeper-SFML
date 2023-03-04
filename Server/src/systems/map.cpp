/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** map.cpp
*/

#include "../../include/systems/map.hpp"

extern eecsge::Coordinator gCoordinator;

void MapSystem::update()
{
    for (auto entity : mEntities) {
        auto &tile = gCoordinator.GetComponent<Tile>(entity);

        if (tile.x == x && tile.y == y) {
            if (button == sf::Mouse::Button::Right)
                tile.sValue = 11;
            else
                tile.sValue = tile.value;

            x = y = -1;
            button = sf::Mouse::Button::Middle;
        }
    }
}

void MapSystem::revealTile(eecsge::Event &event)
{
    x = event.GetParam<int>(Events::RevealTile::Reveal::X);
    y = event.GetParam<int>(Events::RevealTile::Reveal::Y);
    button = event.GetParam<sf::Mouse::Button>(Events::RevealTile::Reveal::BUTTON);
}
