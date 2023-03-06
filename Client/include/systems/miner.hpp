/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** miner.hpp
*/

#pragma once

#include <iostream>
#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>

#include <EECSGE/Physics.hpp>
#include "../events/Input.hpp"
#include "../macros.hpp"


class MinerSystem : public eecsge::System {
    public:
        void update(sf::Event event);
};
