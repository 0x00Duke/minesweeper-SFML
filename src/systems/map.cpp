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
#include "include/events/Input.hpp"

extern Coordinator gCoordinator;

void MapSystem::init()
{
    gCoordinator.AddListener(METHOD_LISTENER(Events::Inputs::CLICK, MapSystem::clickHandler));
}

void MapSystem::update(sf::Event event, sf::RenderWindow *window)
{
    for (auto entity : mEntities) {
		auto& drawable = gCoordinator.GetComponent<Drawable>(entity);
        auto& tile = gCoordinator.GetComponent<Tile>(entity);

        if (x == tile.x && y == tile.y)
            if (button == sf::Mouse::Left) tile.sValue=tile.value;
            else if (button == sf::Mouse::Right) tile.sValue=11;

        drawable.rect = sf::IntRect(tile.sValue * 32, 0, 32, 32);
    }
}

void MapSystem::clickHandler(Event &event)
{
    x = event.GetParam<int>(Events::Inputs::Click::X) / 32;
    y = event.GetParam<int>(Events::Inputs::Click::Y) / 32;
    button = event.GetParam<sf::Mouse::Button>(Events::Inputs::Click::BUTTON);
}
