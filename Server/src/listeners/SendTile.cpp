/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** SendTile.cpp
*/

#include "../../include/listeners/SendTile.hpp"

extern eecsge::Coordinator gCoordinator;

void SendTileListener::init(std::shared_ptr<ClientsSystem> clientsSystem)
{
    _clientsSystem = clientsSystem;
    gCoordinator.AddListener(METHOD_LISTENER(Events::SendTile::SENDTILE, SendTileListener::SendTile));
}

void SendTileListener::SendTile(eecsge::Event &event)
{
    sf::Packet packet;
    std::string x = event.GetParam<std::string>(Events::SendTile::SendTile::X);
    std::string y = event.GetParam<std::string>(Events::SendTile::SendTile::Y);
    std::string value = event.GetParam<std::string>(Events::SendTile::SendTile::VALUE);
    
    std::string send_message = "reveal;" + x + ";" + y + ";" + value;
    packet.clear();
    packet << send_message;

    _clientsSystem->BroadcastPacket(packet);
}
