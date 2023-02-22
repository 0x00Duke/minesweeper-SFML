/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** map.hpp
*/

#pragma once

#include <EECSGE/EECSGE.hpp>

#include "../components/tile.hpp"
#include "../events/RevealTile.hpp"
#include "../macros.hpp"

class MapSystem : public System {
    public:
        void update();
        void revealTile(Event &event);
    
    private:
        int x = -1;
        int y = -1;
        int value = 0;
};
