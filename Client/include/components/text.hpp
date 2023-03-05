/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** text.hpp
*/

#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>

struct Text
{
    std::string string;
    sf::Text text;
    sf::Font font;
    sf::Color color;
    int size;
    int x;
    int y;
};
