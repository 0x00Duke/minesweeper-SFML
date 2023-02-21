/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** background.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <EECSGE/EECSGE.hpp>

class newBackgroundSystem : public System {
    public:
        void update(sf::Event event);
};
