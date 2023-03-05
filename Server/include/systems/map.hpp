/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** map.hpp
*/

#pragma once

#include <EECSGE/Core.hpp>

#include "../components/tile.hpp"
#include "../events/RevealTile.hpp"

class MapSystem : public eecsge::System {
    public:
        void update();
        void revealTile(eecsge::Event &event);
    
    private:
        int x = -1;
        int y = -1;
        sf::Mouse::Button button = sf::Mouse::Button::Middle;
};
