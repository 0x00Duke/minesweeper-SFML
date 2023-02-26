/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Input.hpp
*/

#pragma once

#include <iostream>

#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>
#include <EECSGE/Physics.hpp>

namespace Events::Inputs
{
    const eecsge::EventId CLICK = std::hash<std::string>{}("ClickEvent");
} // namespace Events::Inputs

namespace Events::Inputs::Click
{
    const eecsge::ParamId BUTTON = std::hash<std::string>{}("clickButton");
    const eecsge::ParamId X = std::hash<std::string>{}("clickPosX");
    const eecsge::ParamId Y = std::hash<std::string>{}("clickPosY");
} // namespace Events::Inputs::::Click
