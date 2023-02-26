/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** map.hpp
*/

#pragma once

#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>
#include <EECSGE/Physics.hpp>

#include "../components/tile.hpp"
#include "../events/RevealTile.hpp"
#include "../macros.hpp"

class MapSystem : public eecsge::System {
    public:
        void update();
        void revealTile(eecsge::Event &event);
    
    private:
        int x = -1;
        int y = -1;
        int value = 0;
};
