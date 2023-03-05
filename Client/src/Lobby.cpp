/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Lobby.cpp
*/

#include "../include/Lobby.hpp"

Lobby::Lobby(sf::RenderWindow *window, sf::TcpSocket *socket)
{
    _window = window;
    _socket = socket;
}

Lobby::~Lobby()
{
}

std::tuple<std::string, std::string> Lobby::splitIp(sf::String ip)
{
    std::string delimiter = ":";
    std::string ipString = ip;

    size_t pos = ip.find(delimiter);
    if (pos == std::string::npos) {
        std::cout << "Error: Invalid ip" << std::endl;
        return std::make_tuple("", "");
    }

    std::string portString = ipString.substr(pos + 1, ipString.length());
    ipString = ipString.substr(0, pos);

    return std::make_tuple(ipString, portString);
}

bool Lobby::connectToServer(sf::String ip)
{
    std::cout << "Connecting" << std::endl;

    std::tuple<std::string, std::string> ipTuple = splitIp(ip);
    if (std::get<0>(ipTuple) == "" || std::get<1>(ipTuple) == "")
        return false;
    
    std::cout << "Ip: " << std::get<0>(ipTuple) << std::endl;
    std::cout << "Port: " << std::get<1>(ipTuple) << std::endl;

    unsigned short port = (unsigned short) strtoul(std::get<1>(ipTuple).c_str(), NULL, 0);

    if (_socket->connect(std::get<0>(ipTuple), port) != sf::Socket::Done) {
        logl("Could not connect to the server\n");
        return false;
    }

    logl("Connected to the server\n");
    return true;
}

int Lobby::connectionLobby()
{
    sf::Font font;
    if (!font.loadFromFile(FONT_PATH))
    {
        std::cerr << "Error: Font not found" << std::endl;
        _window->close();
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
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _window->close();
                return 0;
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 8) {
                    if (ip.getSize() > 0) {
                        ip.erase(ip.getSize() - 1, ip.getSize());
                        inputText.setString(IP_TEXT + ip);
                    }
                } else if (event.text.unicode == 10) {
                    if (ip.getSize() > 0 && connectToServer(ip)) {

                        inputText.setString("Connected to server");
                        inputText.setPosition(SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 - 50);
                        _window->clear(sf::Color::White);
                        _window->draw(inputText);
                        _window->display();
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
