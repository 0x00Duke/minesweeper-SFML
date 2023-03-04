/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** main.cpp
*/

#include "../include/Server.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: ./server [port]" << std::endl;
        return 84;
    }
    unsigned short port = (unsigned short) strtoul(av[1], NULL, 0);

    Server server(port);
    server.run();
    return 0;
}