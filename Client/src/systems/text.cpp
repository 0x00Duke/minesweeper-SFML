/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** text.cpp
*/

#include "../../include/systems/text.hpp"

extern eecsge::Coordinator gCoordinator;

void TextSystem::update(sf::RenderWindow *window)
{
    for (auto entity : mEntities) {
        auto &text = gCoordinator.GetComponent<Text>(entity);

        text.text.setFont(text.font);
        text.text.setString(text.string);
        text.text.setCharacterSize(text.size);
        text.text.setFillColor(text.color);
        text.text.setPosition(text.x, text.y);
        window->draw(text.text);
    }
}
