/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** click.hpp
*/

#pragma once

#include <SFML/Window.hpp>

// enum ClickType
// {
//     LEFT,
//     RIGHT,
//     NONE
// };

struct Click
{
    sf::Mouse::Button button;

    int x;
    int y;
};
