/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** SendTile.hpp
*/

#pragma once

#include <SFML/Network.hpp>

#include <EECSGE/Core.hpp>

#include "../systems/clients.hpp"
#include "../components/tile.hpp"
#include "../events/SendTile.hpp"

class SendTileListener {
    public:
        void init(std::shared_ptr<ClientsSystem> clientsSystem);
    private:
        void SendTile(eecsge::Event &event);
        std::shared_ptr<ClientsSystem> _clientsSystem;
};