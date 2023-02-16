/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** game.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <EECSGE/EECSGE.hpp>


class Game
{
public:
    Game();
    ~Game();

    void run();
};