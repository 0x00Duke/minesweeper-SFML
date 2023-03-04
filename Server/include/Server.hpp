/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Server.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <thread>
#include <vector>
#include <chrono>
#include <string.h>

#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>
#include <EECSGE/Physics.hpp>

#include "inits.hpp"
#include "listeners/RevealTile.hpp"

#define MAX_RAW_DATA 256
#define logl(x) std::cout << x << std::endl
#define log(x) std::cout << x

class Server
{
private:
    sf::TcpListener listener;
    std::vector<sf::TcpSocket *> client_array;
    unsigned short listen_port;

    std::shared_ptr<MapSystem> mapSystem;

public:
    Server(unsigned short);
    ~Server();
    void run();
    
    void ConnectClients(std::vector<sf::TcpSocket *> *);
    void DisconnectClient(sf::TcpSocket *, size_t);
    void ReceivePacket(sf::TcpSocket *, size_t);
    void BroadcastPacket(sf::Packet &, sf::IpAddress, unsigned short);
    void ManagePackets();
};
