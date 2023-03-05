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

        if (tile.x == y && tile.y == x) {
            if (button == sf::Mouse::Button::Right)
                tile.sValue = 11;
            else
                tile.sValue = tile.value;
            
            eecsge::Event event(Events::SendTile::SENDTILE);
            event.SetParam(Events::SendTile::SendTile::X, std::to_string(x));
            event.SetParam(Events::SendTile::SendTile::Y, std::to_string(y));
            event.SetParam(Events::SendTile::SendTile::VALUE, std::to_string(tile.sValue));
            gCoordinator.SendEvent(event);

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
