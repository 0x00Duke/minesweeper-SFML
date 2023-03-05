/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** EndGame.hpp
*/

#pragma once

#include <EECSGE/Core.hpp>

#include "../systems/clients.hpp"
#include "../components/tile.hpp"
#include "../events/EndGame.hpp"

class EndGameListener {
    public:
        void init(std::shared_ptr<ClientsSystem> clientsSystem);
    private:
        void SendStatus(eecsge::Event &event);
        std::shared_ptr<ClientsSystem> _clientsSystem;
};
