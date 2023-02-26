/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** background.cpp
*/

#include "../../include/systems/background.hpp"
#include "../../include/macros.hpp"

extern eecsge::Coordinator gCoordinator;

void newBackgroundSystem::update()
{
    for (auto entity : mEntities) {
        auto &rigidBody = gCoordinator.GetComponent<eecsge::RigidBody>(entity);
        auto &drawable = gCoordinator.GetComponent<Drawable>(entity);

        if (rigidBody.position.x - SCREEN_WIDTH <= -BG_WIDTH && rigidBody.velocity.x < 0) {
            rigidBody.velocity.x = 0;
            rigidBody.velocity.y = -1;
        }
        else if (rigidBody.position.y - SCREEN_HEIGHT <= -BG_HEIGHT && rigidBody.velocity.y < 0) {
            rigidBody.velocity.y = 0;
            rigidBody.velocity.x = 1;
        }
        else if (rigidBody.position.x > 0 && rigidBody.velocity.x > 0) {
            rigidBody.velocity.x = 0;
            rigidBody.velocity.y = 1;
        }
        else if (rigidBody.position.y > 0 && rigidBody.velocity.y > 0) {
            rigidBody.velocity.y = 0;
            rigidBody.velocity.x = -1;
        }

        rigidBody.position.x += rigidBody.velocity.x;
        rigidBody.position.y += rigidBody.velocity.y;
        // drawable.sprite.setPosition(rigidBody.position.x, rigidBody.position.y);
    }
}
