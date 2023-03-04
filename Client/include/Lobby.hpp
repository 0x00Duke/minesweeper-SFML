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

#define logl(x) std::cout << x << std::endl
#define log(x) std::cout << x

class Lobby
{
private:
    sf::RenderWindow *_window;
    bool connectToServer(sf::String ip);
    std::tuple<std::string, std::string> splitIp(sf::String ip);

    sf::TcpSocket *_socket;

public:
    Lobby(sf::RenderWindow *window, sf::TcpSocket *socket);
    ~Lobby();
    int connectionLobby();
};
