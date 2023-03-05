/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Win.hpp
*/

#pragma once

#include <EECSGE/Core.hpp>

namespace Events::EndGame
{
    const eecsge::EventId ENDGAME = std::hash<std::string>{}("EndGameEvent");
} // namespace Events::EndGame

namespace Events::EndGame::EndGame
{
    const eecsge::ParamId status = std::hash<std::string>{}("EndGameStatus");
} // namespace Events::EndGame::EndGame