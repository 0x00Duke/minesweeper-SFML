/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** miner.hpp
*/

#pragma once

#include <iostream>
#include <EECSGE/EECSGE.hpp>
#include "../events/Input.hpp"


class MinerSystem : public System {
    public:
        void update(sf::Event event);
};
