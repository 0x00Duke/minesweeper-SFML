/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Server.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>

#include <EECSGE/Physics.hpp>

#include "inits.hpp"
#include "listeners/RevealTile.hpp"

class Server
{
private:
    std::shared_ptr<MapSystem> mapSystem;
public:
    Server(/* args */);
    ~Server();
    void run();
};
