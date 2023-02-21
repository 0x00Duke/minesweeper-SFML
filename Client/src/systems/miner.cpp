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

        if (event.type == sf::Event::MouseButtonPressed) {

            Event newEvent(Events::Inputs::CLICK);
            newEvent.SetParam(Events::Inputs::Click::X, event.mouseButton.x);
            newEvent.SetParam(Events::Inputs::Click::Y, event.mouseButton.y);
            newEvent.SetParam(Events::Inputs::Click::BUTTON, event.mouseButton.button);

            gCoordinator.SendEvent(newEvent);
        }
    }
}
