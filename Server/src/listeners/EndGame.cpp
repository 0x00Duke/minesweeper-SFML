/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** EndGame.hpp
*/

#include "../../include/listeners/EndGame.hpp"

extern eecsge::Coordinator gCoordinator;

void EndGameListener::init(std::shared_ptr<ClientsSystem> clientsSystem)
{
    _clientsSystem = clientsSystem;
    gCoordinator.AddListener(METHOD_LISTENER(Events::EndGame::ENDGAME, EndGameListener::SendStatus));
}

void EndGameListener::SendStatus(eecsge::Event &event)
{
    sf::Packet packet;
    std::string status = event.GetParam<std::string>(Events::EndGame::EndGame::status);
    
    std::string send_message = "endGame;" + status;
    packet.clear();
    packet << send_message;

    _clientsSystem->BroadcastPacket(packet);
}