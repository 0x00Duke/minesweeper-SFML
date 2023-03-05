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

#define logl(x) std::cout << x << std::endl
#define log(x) std::cout << x

class ClientsSystem : public eecsge::System {
    public:
        void update();
        void BroadcastPacket(sf::Packet packet);
    private:
        void ReceivePacket(Client client, eecsge::Entity entity);
        void DisconnectClient(Client client, eecsge::Entity entity);
};
