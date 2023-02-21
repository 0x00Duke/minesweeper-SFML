/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** ClickListener.cpp
*/

#include "../../include/listeners/ClickListener.hpp"

extern Coordinator gCoordinator;

void ClickListener::init()
{
    gCoordinator.AddListener(METHOD_LISTENER(Events::Inputs::CLICK, ClickListener::clickHandler));
}

void ClickListener::clickHandler(Event &event)
{
    std::cout << "click: " << std::endl;
    std::cout << "x: " << event.GetParam<int>(Events::Inputs::Click::X) / 32 << std::endl;
    std::cout << "y: " << event.GetParam<int>(Events::Inputs::Click::Y) / 32 << std::endl;
    std::cout << "button: " << event.GetParam<sf::Mouse::Button>(Events::Inputs::Click::BUTTON) << std::endl;
}