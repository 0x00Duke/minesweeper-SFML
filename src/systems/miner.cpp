/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** Miner.cpp
*/

#include "include/systems/miner.hpp"
#include "include/components/click.hpp"
#include "include/events/Input.hpp"
extern Coordinator gCoordinator;

void MinerSystem::Dig(Transform &transform, Movement &movement)
{
    std::cout << "Digging" << std::endl;
}

void MinerSystem::ManagePresses(sf::Keyboard::Key key, Movement &movement, Transform &transform)
{
    // switch (key)
    // {
    // case sf::Keyboard::Up:
    //     movement.velocity.y = -1;
    //     break;
    // case sf::Keyboard::Down:
    //     movement.velocity.y = 1;
    //     break;
    // case sf::Keyboard::Left:
    //     movement.velocity.x = -1;
    //     break;
    // case sf::Keyboard::Right:
    //     movement.velocity.x = 1;
    //     break;
    // case sf::Keyboard::Space:
    //     Dig(transform, movement);
    //     break;
    // default:
    //     break;
    // }
}

void MinerSystem::ManageReleases(sf::Keyboard::Key key, Movement &movement)
{
    // switch (key)
    // {
    // case sf::Keyboard::Up:
    //     movement.velocity.y = 0;
    //     break;
    // case sf::Keyboard::Down:
    //     movement.velocity.y = 0;
    //     break;
    // case sf::Keyboard::Left:
    //     movement.velocity.x = 0;
    //     break;
    // case sf::Keyboard::Right:
    //     movement.velocity.x = 0;
    //     break;
    // default:
    //     break;
    // }
}

void MinerSystem::update(sf::Event event)
{
    float speed = 1;
    for (auto entity : mEntities) {
        auto &click = gCoordinator.GetComponent<Click>(entity);

        if (event.type == sf::Event::MouseButtonPressed) {
            click.button = event.mouseButton.button;

            Event newEvent(Events::Inputs::CLICK);
            newEvent.SetParam(Events::Inputs::Click::X, event.mouseButton.x);
            newEvent.SetParam(Events::Inputs::Click::Y, event.mouseButton.y);
            newEvent.SetParam(Events::Inputs::Click::BUTTON, click.button);

            gCoordinator.SendEvent(newEvent);
        }
    }
}
