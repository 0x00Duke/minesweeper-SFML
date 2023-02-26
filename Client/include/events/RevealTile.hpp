/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** RevealTile.hpp
*/

#pragma once

#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>

#include <EECSGE/Physics.hpp>

namespace Events::RevealTile
{
    const eecsge::EventId REVEAL = std::hash<std::string>{}("RevealTileEvent");
} // namespace Events::RevealTile

namespace Events::RevealTile::Reveal
{
    const eecsge::ParamId X = std::hash<std::string>{}("revealPosX");
    const eecsge::ParamId Y = std::hash<std::string>{}("revealPosY");
    const eecsge::ParamId VALUE = std::hash<std::string>{}("revealValue");
} // namespace Events::RevealTile::Reveal
