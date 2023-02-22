/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** background.cpp
*/

#include "../../include/systems/background.hpp"
#include "../../include/macros.hpp"

extern Coordinator gCoordinator;

void newBackgroundSystem::update()
{
    for (auto entity : mEntities) {
        auto &transform = gCoordinator.GetComponent<Transform>(entity);
        auto &drawable = gCoordinator.GetComponent<Drawable>(entity);
        auto &movement = gCoordinator.GetComponent<Movement>(entity);

        if (transform.position.x - SCREEN_WIDTH <= -BG_WIDTH && movement.velocity.x < 0) {
            movement.velocity.x = 0;
            movement.velocity.y = -0.5;
        }
        else if (transform.position.y - SCREEN_HEIGHT <= -BG_HEIGHT && movement.velocity.y < 0) {
            movement.velocity.y = 0;
            movement.velocity.x = 0.5;
        }
        else if (transform.position.x > 0 && movement.velocity.x > 0) {
            movement.velocity.x = 0;
            movement.velocity.y = 0.5;
        }
        else if (transform.position.y > 0 && movement.velocity.y > 0) {
            movement.velocity.y = 0;
            movement.velocity.x = -0.5;
        }
        transform.position.x += movement.velocity.x;
        transform.position.y += movement.velocity.y;
        drawable.sprite.setPosition(transform.position);
    }
}
