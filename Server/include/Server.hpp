/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Server.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <thread>
#include <vector>
#include <chrono>
#include <string.h>

#include <EECSGE/Core.hpp>

#include "inits.hpp"
#include "listeners/RevealTile.hpp"
#include "listeners/SendTile.hpp"
#include "listeners/EndGame.hpp"

#define MAX_RAW_DATA 256
#define logl(x) std::cout << x << std::endl
#define log(x) std::cout << x

class Server
{
private:
    sf::TcpListener listener;
    unsigned short listen_port;

    std::shared_ptr<MapSystem> mapSystem;
    std::shared_ptr<ClientsSystem> clientsSystem;
    std::shared_ptr<WinLooseSystem> winLooseSystem;

    bool isRunning = true;

public:
    Server(unsigned short);
    ~Server();
    void run();
    
    void ConnectClients();
};
