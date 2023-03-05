/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** miner.cpp
*/

#include "../../include/systems/miner.hpp"
#include "../../include/components/click.hpp"

extern eecsge::Coordinator gCoordinator;

void MinerSystem::update(sf::Event event)
{
    for (auto entity : mEntities) {
        auto &click = gCoordinator.GetComponent<Click>(entity);

        if (event.type == sf::Event::MouseButtonReleased) {
            int x = event.mouseButton.x / 64;
            int y = event.mouseButton.y / 64;

            if (x <= 0 || y <= 0 || x > 10 || y > 10)
                return;
            eecsge::Event newEvent(Events::Inputs::CLICK);
            newEvent.SetParam(Events::Inputs::Click::X, std::to_string(x));
            newEvent.SetParam(Events::Inputs::Click::Y, std::to_string(y));
            newEvent.SetParam(Events::Inputs::Click::BUTTON, event.mouseButton.button);

            gCoordinator.SendEvent(newEvent);
        }
    }
}
