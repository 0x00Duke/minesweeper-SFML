/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** miner.cpp
*/

#include "../../include/systems/miner.hpp"
#include "../../include/components/click.hpp"

extern Coordinator gCoordinator;

void MinerSystem::update(sf::Event event)
{
    for (auto entity : mEntities) {
        auto &click = gCoordinator.GetComponent<Click>(entity);

        if (event.type == sf::Event::MouseButtonReleased) {
            int x = event.mouseButton.x / 64;
            int y = event.mouseButton.y / 64;

            if (x <= 0 || y <= 0 || x > 10 || y > 10)
                return;
            Event newEvent(Events::Inputs::CLICK);
            newEvent.SetParam(Events::Inputs::Click::X, x);
            newEvent.SetParam(Events::Inputs::Click::Y, y);
            newEvent.SetParam(Events::Inputs::Click::BUTTON, event.mouseButton.button);

            gCoordinator.SendEvent(newEvent);
        }
    }
}