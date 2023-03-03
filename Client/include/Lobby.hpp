/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Lobby.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "macros.hpp"

class Lobby
{
private:
    sf::RenderWindow *_window;
    bool connectToServer(sf::String ip);
    std::tuple<std::string, std::string> splitIp(sf::String ip);

public:
    Lobby(sf::RenderWindow *window);
    ~Lobby();
    int connectionLobby();
};
