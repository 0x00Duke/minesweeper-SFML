/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** init.hpp
*/

#pragma once

#include "components/tile.hpp"
#include "components/click.hpp"
#include "systems/background.hpp"
#include "systems/miner.hpp"
#include "systems/map.hpp"

#include "macros.hpp"

// #include "systems/winLoose.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>
#include <EECSGE/Physics.hpp>

void initSignatures();
int initBackground();
int initTiles();
void initMiner();
