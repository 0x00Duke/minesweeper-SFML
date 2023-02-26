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

        if (tile.x == x && tile.y == y) {
            if (button == sf::Mouse::Button::Right)
                tile.sValue = 11;
            else
                tile.sValue = tile.value;
            
            // print the map
            for (int i = 1; i <= 10; i++) {
                for (int j = 1; j <= 10; j++){
                    std::cout << gCoordinator.GetComponent<Tile>(i * 10 + j).sValue << " ";
                }
                std::cout << std::endl;
            }

            x = y = -1;
            button = sf::Mouse::Button::Middle;
        }
    }
}

void MapSystem::revealTile(Event &event)
{
    x = event.GetParam<int>(Events::RevealTile::Reveal::X);
    y = event.GetParam<int>(Events::RevealTile::Reveal::Y);
    button = event.GetParam<sf::Mouse::Button>(Events::RevealTile::Reveal::BUTTON);
}
