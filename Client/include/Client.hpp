/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Client.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <EECSGE/EECSGE.hpp>

#include "inits.hpp"
#include "events/Input.hpp"
#include "listeners/ClickListener.hpp"

class Client
{
private:
    /* systems */
    std::shared_ptr<DrawSystem> drawSystem;
    std::shared_ptr<MovementSystem> movementSystem;
    std::shared_ptr<newBackgroundSystem> backgroundSystem;
    std::shared_ptr<MinerSystem> minerSystem;
    // std::shared_ptr<MapSystem> mapSystem;
public:
    Client(/* args */);
    ~Client();

    void run();
};
