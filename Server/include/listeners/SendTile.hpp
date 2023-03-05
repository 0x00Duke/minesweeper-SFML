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
#include "../systems/clients.hpp"

class SendTileListener {
    public:
        void init(std::shared_ptr<ClientsSystem> clientsSystem);
    private:
        std::shared_ptr<ClientsSystem> _clientsSystem;
        void SendTile(eecsge::Event &event);
};