/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** inits.hpp
*/

#pragma once

#include "components/tile.hpp"
#include "systems/map.hpp"

#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>

#include <EECSGE/Physics.hpp>

void initSignatures();
void initTiles();
std::vector<std::vector<int>> initGrid();
