/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** init.hpp
*/

#pragma once

#include "include/components/tile.hpp"
#include "include/systems/background.hpp"
#include "include/systems/map.hpp"
#include "include/systems/winLoose.hpp"
#include "include/systems/miner.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <EECSGE/EECSGE.hpp>

void initBackground();
void initMap();
void initSignatures();
