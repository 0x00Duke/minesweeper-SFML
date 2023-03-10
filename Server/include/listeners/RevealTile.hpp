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
#include "../systems/map.hpp"

class RevealTileListener {
    public:
        void init(std::shared_ptr<MapSystem> mapSystem);
    private:
        void callMapSystem(eecsge::Event &event);
        std::shared_ptr<MapSystem> _mapSystem;
};

