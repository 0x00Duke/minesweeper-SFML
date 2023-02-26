/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** background.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>

#include <EECSGE/Physics.hpp>

class newBackgroundSystem : public System {
    public:
        void update();
};
