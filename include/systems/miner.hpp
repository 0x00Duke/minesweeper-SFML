/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** player.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <EECSGE/EECSGE.hpp>

class MinerSystem : public System {
    public:
        void update(sf::Event event);
    private:
        void ManagePresses(sf::Keyboard::Key key, Movement &movement, Transform &transform);
        void ManageReleases(sf::Keyboard::Key key, Movement &movement);
        void Dig(Transform &transform, Movement &movement);
};
