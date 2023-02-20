/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** map.cpp
*/

#include "include/systems/map.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

extern Coordinator gCoordinator;

void MapSystem::update(sf::Event event, sf::RenderWindow *window)
{
    for (auto entity : mEntities) {
		auto& drawable = gCoordinator.GetComponent<Drawable>(entity);
        auto& tile = gCoordinator.GetComponent<Tile>(entity);

        sf::Vector2i pos = sf::Mouse::getPosition(*window);
        int x = pos.x/32;
        int y = pos.y/32;

        if (event.type == sf::Event::MouseButtonPressed)
            if (x == tile.x && y == tile.y)
                if (event.key.code == sf::Mouse::Left) tile.sValue=tile.value;
                else if (event.key.code == sf::Mouse::Right) tile.sValue=11;

        drawable.sprite.setTextureRect(sf::IntRect(tile.sValue * 32, 0, 32, 32));
    }
}
