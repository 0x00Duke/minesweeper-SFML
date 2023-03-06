/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** EndGame.cpp
*/

#include "../../include/listeners/EndGame.hpp"

extern eecsge::Coordinator gCoordinator;

void EndGameListener::init(sf::RenderWindow *window)
{
    _window = window;
    gCoordinator.AddListener(METHOD_LISTENER(Events::EndGame::ENDGAME, EndGameListener::callEndGame));
}

void EndGameListener::callEndGame(eecsge::Event &event)
{
    std::string status = event.GetParam<std::string>(Events::EndGame::EndGame::status);
    std::string text;

    if (status == "win")
        text = "You Win !";
    else
        text = "You Lose !";

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/font.ttf")) {
        std::cout << "Error: font not found" << std::endl;
        return;
    }
    sf::Color color = status == "win" ? sf::Color::Green : sf::Color::Red;

    eecsge::Entity textEntity = gCoordinator.CreateEntity();
    gCoordinator.AddComponent(textEntity, Text{
                                              text,
                                              sf::Text(),
                                              font,
                                              color,
                                              100,
                                              350,
                                              300});
}
