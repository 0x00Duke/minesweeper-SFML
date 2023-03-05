/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** SendTile.cpp
*/

#include "../../include/listeners/SendTile.hpp"

void SendTileListener::init()
{
    gCoordinator.AddListener(METHOD_LISTENER(Events::SendTile::SENDTILE, SendTileListener::SendTile));
}

void SendTileListener::SendTile()
{
    sf::Packet packet;
    std::vector<sf::TcpSocket *> client_array = event.GetParam<std::vector<sf::TcpSocket *>>(Events::SendTile::SendTile::clients);
    std::string x = event.GetParam<std::string>(Events::SendTile::SendTile::X);
    std::string y = event.GetParam<std::string>(Events::SendTile::SendTile::Y);
    std::string value = event.GetParam<std::string>(Events::SendTile::SendTile::VALUE);
    
    packet << x << ";" << y << ";" << value;

    for (size_t iterator = 0; iterator < client_array.size(); iterator++) {
        sf::TcpSocket *client = client_array[iterator];
        if (client->send(packet) != sf::Socket::Done) {
            logl("Could not send packet on broadcast");
        }
    }
}
