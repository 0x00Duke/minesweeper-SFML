/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** ClickListener.hpp
*/

#pragma once

#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>
#include <EECSGE/Physics.hpp>

#include <SFML/Network.hpp>

#include "../events/Input.hpp"

#define logl(x) std::cout << x << std::endl
#define log(x) std::cout << x

class ClickListener {
public:
    void init(sf::TcpSocket *socket);
    void clickHandler(eecsge::Event &event);
private:
    sf::TcpSocket *_socket;
};
