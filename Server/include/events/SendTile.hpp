/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** SendTile.hpp
*/

#pragma once

#include <EECSGE/Graphics.hpp>
#include <EECSGE/Physics.hpp>

namespace Events::SendTile
{
    const eecsge::EventId SENDTILE = std::hash<std::string>{}("SendTileEvent");
} // namespace Events::SendTile

namespace Events::SendTile::SendTile
{
    const eecsge::ParamId X = std::hash<std::string>{}("revealPosX");
    const eecsge::ParamId Y = std::hash<std::string>{}("revealPosY");
    const eecsge::ParamId VALUE = std::hash<std::string>{}("revealValue");
} // namespace Events::SendTile::Reveal
