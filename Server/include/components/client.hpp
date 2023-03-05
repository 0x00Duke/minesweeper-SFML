/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** client.hpp
*/

#pragma once

#include <SFML/Network.hpp>

struct Client
{
    sf::TcpSocket *socket;
};
