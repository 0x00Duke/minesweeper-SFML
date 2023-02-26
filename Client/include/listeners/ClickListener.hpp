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
#include "../events/Input.hpp"

class ClickListener {
public:
    void init();
    void clickHandler(Event &event);
};
