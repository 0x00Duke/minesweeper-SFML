/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** clients.cpp
*/

#include "../../include/systems/clients.hpp"

extern eecsge::Coordinator gCoordinator;

void ClientsSystem::DisconnectClient(Client client, eecsge::Entity entity)
{
    client.socket->disconnect();
    delete (client.socket);
}

void ClientsSystem::ReceivePacket(Client client, eecsge::Entity entity)
{
    sf::Packet packet;
    if (client.socket->receive(packet) == sf::Socket::Disconnected) {
        DisconnectClient(client, entity);
        std::cout << "Client disconnected" << std::endl;
        return;
    }

    if (packet.getDataSize() > 0) {
        std::string received_message;
        packet >> received_message;
        packet.clear();

        std::vector<std::string> split_message;
        std::string delimiter = ";";

        size_t pos = 0;
        std::string token;
        while ((pos = received_message.find(delimiter)) != std::string::npos) {
            token = received_message.substr(0, pos);
            split_message.push_back(token);
            received_message.erase(0, pos + delimiter.length());
        }
        split_message.push_back(received_message);

        std::cout << split_message[0] << split_message[1] << split_message[2] << std::endl;

        eecsge::Event event(Events::RevealTile::REVEAL);
        event.SetParam(Events::RevealTile::Reveal::X, std::stoi(split_message[1]));
        event.SetParam(Events::RevealTile::Reveal::Y, std::stoi(split_message[2]));

        if (split_message[0] == "reveal")
            event.SetParam(Events::RevealTile::Reveal::BUTTON, sf::Mouse::Button::Left);
        else if (split_message[0] == "flag")
            event.SetParam(Events::RevealTile::Reveal::BUTTON, sf::Mouse::Button::Right);
        else
            return;
        gCoordinator.SendEvent(event);
    }
}

void ClientsSystem::BroadcastPacket(sf::Packet packet)
{
    for (auto entity : mEntities) {
        auto &client = gCoordinator.GetComponent<Client>(entity);

        if (client.socket->getRemoteAddress() == sf::IpAddress::None)
            continue;
        if (client.socket->send(packet) != sf::Socket::Done) {
            logl("Could not send packet on broadcast");
        }
    }
}

void ClientsSystem::update()
{
    for (auto entity : mEntities) {
        auto &client = gCoordinator.GetComponent<Client>(entity);

        // if the client is not connected, skip it
        if (client.socket->getRemoteAddress() == sf::IpAddress::None)
            continue;
        ReceivePacket(client, entity);
    }
}
