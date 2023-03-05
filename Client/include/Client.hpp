/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Client.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>
#include <EECSGE/Physics.hpp>

#include <thread>
#include <chrono>

#define logl(x) std::cout << x << std::endl
#define log(x) std::cout << x

#include "Lobby.hpp"

#include "inits.hpp"
#include "systems/map.hpp"
#include "systems/text.hpp"
#include "events/Input.hpp"
#include "listeners/ClickListener.hpp"
#include "listeners/RevealTile.hpp"
#include "listeners/EndGame.hpp"
#include "macros.hpp"

class Client
{
private:
    /* systems */
    std::shared_ptr<eecsge::DrawSystem> drawSystem;
    std::shared_ptr<newBackgroundSystem> backgroundSystem;
    std::shared_ptr<MinerSystem> minerSystem;
    std::shared_ptr<MapSystem> mapSystem;
    std::shared_ptr<TextSystem> textSystem;

    sf::TcpSocket socket;
    sf::Packet last_packet;

    void emitRevealTileEvent(std::string);
    void proccessPacket(std::string);

public:
    Client(/* args */);
    ~Client();

    // void Connect(const char *, unsigned short);
    void ReceivePackets(sf::TcpSocket *);
    void SendPacket(sf::Packet &);
    // void Run();
    void run();
};
