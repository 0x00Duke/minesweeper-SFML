/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** clients.hpp
*/

#pragma once

#include <EECSGE/Core.hpp>
#include <SFML/Network.hpp>

#include <iostream>

#include "../events/RevealTile.hpp"

#include "../components/client.hpp"

class ClientsSystem : public eecsge::System {
    public:
        void update();
    private:
        void ReceivePacket(Client client, eecsge::Entity entity);
        void DisconnectClient(Client client, eecsge::Entity entity);
};
