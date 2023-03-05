/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** ClickListener.cpp
*/

#include "../../include/listeners/ClickListener.hpp"

extern eecsge::Coordinator gCoordinator;

void ClickListener::init(sf::TcpSocket *socket)
{
    _socket = socket;
    gCoordinator.AddListener(METHOD_LISTENER(Events::Inputs::CLICK, ClickListener::clickHandler));
}

void ClickListener::clickHandler(eecsge::Event &event)
{
    std::string sendingString;
    sf::Packet packet;

    std::string x = event.GetParam<std::string>(Events::Inputs::Click::X);
    std::string y = event.GetParam<std::string>(Events::Inputs::Click::Y);
    
    std::string buttonString;
    sf::Mouse::Button button = event.GetParam<sf::Mouse::Button>(Events::Inputs::Click::BUTTON);

    if (button == sf::Mouse::Button::Left)
        buttonString = "reveal";
    else if (button == sf::Mouse::Button::Right)
        buttonString = "flag";
    else
        return;

    sendingString = buttonString + ";" + x + ";" + y;
    packet << sendingString;

    if (packet.getDataSize() > 0 && _socket->send(packet) != sf::Socket::Done) {
        logl("Could not send packet");
    }
}
