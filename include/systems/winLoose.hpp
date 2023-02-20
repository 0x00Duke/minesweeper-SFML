/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** winLoose.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <EECSGE/EECSGE.hpp>

#include "../components/tile.hpp"

class WinLooseSystem : public System {
    public:
        void update(sf::Event event, sf::RenderWindow *window);
    private:
        void CheckWin(sf::RenderWindow *window);
        void CheckLoose(sf::RenderWindow *window);
};