/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** SendTile.hpp
*/

#pragma once

#include <EECSGE/Core.hpp>

#include <SFML/Network.hpp>

#include "../components/tile.hpp"
#include "../events/SendTile.hpp"
#include "../systems/map.hpp"

class SendTileListener {
    public:
        void init();
    private:
        void SendTile(std::vector<sf::TcpSocket *> client_array);
};