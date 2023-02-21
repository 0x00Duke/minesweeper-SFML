/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** map.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <EECSGE/EECSGE.hpp>

#include "../components/tile.hpp"
#include "../components/click.hpp"

class MapSystem : public System {
    public:
        void update(sf::Event event, sf::RenderWindow *window);
        void init();
        void clickHandler(Event &event);
    private:
        float x, y;
        sf::Mouse::Button button;
};
