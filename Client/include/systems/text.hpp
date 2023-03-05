/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** text.hpp
*/

#pragma once

#include <iostream>
#include <EECSGE/Core.hpp>
#include <EECSGE/Graphics.hpp>
#include <EECSGE/Physics.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../components/text.hpp"

class TextSystem : public eecsge::System {
    public:
        void update(sf::RenderWindow *window);
};
