/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** EndGame.hpp
*/

#pragma once

#include <iostream>

#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>
#include <EECSGE/Physics.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace Events::EndGame
{
    const eecsge::EventId ENDGAME = std::hash<std::string>{}("EndGameEvent");
} // namespace Events::EndGame

namespace Events::EndGame::EndGame
{
    const eecsge::ParamId status = std::hash<std::string>{}("EndGameStatus");
} // namespace Events::EndGame::EndGame
