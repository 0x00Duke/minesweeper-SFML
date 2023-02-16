/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Miner.cpp
*/

#include "include/systems/miner.hpp"
extern Coordinator gCoordinator;

void MinerSystem::Dig(Transform &transform, Movement &movement)
{
    std::cout << "Digging" << std::endl;
}

void MinerSystem::ManagePresses(sf::Keyboard::Key key, Movement &movement, Transform &transform)
{
    switch (key)
    {
    case sf::Keyboard::Up:
        movement.velocity.y = -1;
        break;
    case sf::Keyboard::Down:
        movement.velocity.y = 1;
        break;
    case sf::Keyboard::Left:
        movement.velocity.x = -1;
        break;
    case sf::Keyboard::Right:
        movement.velocity.x = 1;
        break;
    case sf::Keyboard::Space:
        Dig(transform, movement);
        break;
    default:
        break;
    }
}

void MinerSystem::ManageReleases(sf::Keyboard::Key key, Movement &movement)
{
    switch (key)
    {
    case sf::Keyboard::Up:
        movement.velocity.y = 0;
        break;
    case sf::Keyboard::Down:
        movement.velocity.y = 0;
        break;
    case sf::Keyboard::Left:
        movement.velocity.x = 0;
        break;
    case sf::Keyboard::Right:
        movement.velocity.x = 0;
        break;
    default:
        break;
    }
}

void MinerSystem::update(sf::Event event)
{
    float speed = 1;
    for (auto entity : mEntities) {
        auto &movement = gCoordinator.GetComponent<Movement>(entity);
        auto &transform = gCoordinator.GetComponent<Transform>(entity);
        auto &inputKeys = gCoordinator.GetComponent<InputKeys>(entity);

        if (event.type == sf::Event::KeyPressed) {
            ManagePresses(event.key.code, movement, transform);
        }
        if (event.type == sf::Event::KeyReleased) {
            ManageReleases(event.key.code, movement);
        }
    }
}