/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Input.hpp
*/

#pragma once

#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>

#include <EECSGE/Physics.hpp>

namespace Events::Inputs
{
    const EventId CLICK = "ClickEvent"_hash;
} // namespace Events::Inputs

namespace Events::Inputs::Click
{
    const ParamId BUTTON = "clickButton"_hash;
    const ParamId X = "clickPosX"_hash;
    const ParamId Y = "clickPosY"_hash;
} // namespace Events::Inputs::::Click
