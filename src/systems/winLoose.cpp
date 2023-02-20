/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** winLoose.cpp
*/

#include "include/systems/winLoose.hpp"

extern Coordinator gCoordinator;

void WinLooseSystem::CheckLoose(sf::RenderWindow *window)
{
    for (auto const &entity : mEntities) {
        auto &tile = gCoordinator.GetComponent<Tile>(entity);
        if (tile.sValue == 9) {
            std::cout << "You loose !" << std::endl;
            // wait 1 seconds
            sf::sleep(sf::seconds(1));
            window->close();
        }
    }
}

void WinLooseSystem::CheckWin(sf::RenderWindow *window)
{
    for (auto const &entity : mEntities) {
        auto &tile = gCoordinator.GetComponent<Tile>(entity);
        if (tile.sValue != tile.value && tile.sValue != 11)
            return;
    }
    sf::sleep(sf::seconds(1));
    std::cout << "You win !" << std::endl;
    window->close();
}

void WinLooseSystem::update(sf::Event event, sf::RenderWindow *window)
{
    CheckLoose(window);
    CheckWin(window);
}