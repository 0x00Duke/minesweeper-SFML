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
    const EventId REVEAL = "RevealTileEvent"_hash;
} // namespace Events::RevealTile

namespace Events::RevealTile::Reveal
{
    const ParamId X = "revealPosX"_hash;
    const ParamId Y = "revealPosY"_hash;
    const ParamId VALUE = "revealValue"_hash;
} // namespace Events::RevealTile::Reveal
