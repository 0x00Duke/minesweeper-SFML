/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Lobby.cpp
*/

#include "../include/Lobby.hpp"

Lobby::Lobby(sf::RenderWindow *window)
{
    _window = window;
}

Lobby::~Lobby()
{
}

bool Lobby::connectToServer(sf::String ip)
{
    std::cout << "Connecting" << std::endl;
    return true;
}

int Lobby::connectionLobby()
{
    sf::Font font;
    if (!font.loadFromFile(FONT_PATH))
    {
        std::cerr << "Error: Font not found" << std::endl;
        return 84;
    }

    sf::Text inputText;

    inputText.setFont(font);
    inputText.setCharacterSize(45);
    inputText.setFillColor(sf::Color::Black);
    inputText.setString(IP_TEXT);
    inputText.setPosition(SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 - 300);

    sf::String ip;

    sf::Event event;
    while (_window->isOpen())
    {
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                _window->close();
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 8) {
                    if (ip.getSize() > 0) {
                        ip.erase(ip.getSize() - 1, ip.getSize());
                        inputText.setString(IP_TEXT + ip);
                    }
                } else if (event.text.unicode == 10) {
                    if (ip.getSize() > 0 && connectToServer(ip)) {
                        std::cout << "Connected to server" << std::endl;
                        return 0;
                    }
                    std::cout << "Error: Can't connect to server" << std::endl;
                } else if (event.text.unicode < 128) {
                    ip += event.text.unicode;
                    inputText.setString(IP_TEXT + ip);
                }
            }
        }
        _window->clear(sf::Color::White);
        _window->draw(inputText);
        _window->display();
    }
    return 0;
}
