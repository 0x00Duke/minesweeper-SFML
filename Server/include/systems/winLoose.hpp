/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** winLoose.hpp
*/

#pragma once

#include <iostream>

#include <EECSGE/Core.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "../components/tile.hpp"

#include "../events/EndGame.hpp"

class WinLooseSystem : public eecsge::System {
    public:
        bool check();
    private:
        bool CheckWin();
        bool CheckLoose();
};