/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** tile.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

struct Tile
{
    int value;
    int sValue;
    int x, y;
};
