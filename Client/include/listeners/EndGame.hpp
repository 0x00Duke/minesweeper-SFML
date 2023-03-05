/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** EndGame.hpp
*/

#pragma once

#include <iostream>
#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>
#include <EECSGE/Physics.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../events/EndGame.hpp"
#include "../components/text.hpp"

class EndGameListener {
    public:
        void init(sf::RenderWindow *window);
    private:
        sf::RenderWindow *_window;
        void callEndGame(eecsge::Event &event);
};
