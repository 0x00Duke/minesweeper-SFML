/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** inits.cpp
*/

#include "../include/inits.hpp"

extern Coordinator gCoordinator;

void initSignatures()
{
    gCoordinator.RegisterComponent<RigidBody>();
    gCoordinator.RegisterComponent<Drawable>();
    gCoordinator.RegisterComponent<Tile>();
    gCoordinator.RegisterComponent<Click>();

    // set the signature of the systems
    Signature Msignature;
    Msignature.set(gCoordinator.GetComponentType<RigidBody>());
    gCoordinator.SetSystemSignature<MovementSystem>(Msignature);

    Signature Dsignature;
    Dsignature.set(gCoordinator.GetComponentType<RigidBody>());
    Dsignature.set(gCoordinator.GetComponentType<Drawable>());
    gCoordinator.SetSystemSignature<DrawSystem>(Dsignature);

    Signature signatureBackground;
    signatureBackground.set(gCoordinator.GetComponentType<Drawable>());
    gCoordinator.SetSystemSignature<newBackgroundSystem>(signatureBackground);

    Signature signatureMiner;
    signatureMiner.set(gCoordinator.GetComponentType<Click>());
    gCoordinator.SetSystemSignature<MinerSystem>(signatureMiner);

    Signature signatureMap;
    signatureMap.set(gCoordinator.GetComponentType<Tile>());
    signatureMap.set(gCoordinator.GetComponentType<Drawable>());
    gCoordinator.SetSystemSignature<MapSystem>(signatureMap);
}

void initBackground()
{
    Entity background = gCoordinator.CreateEntity();
    sf::Texture *texture = new sf::Texture();

    if (!texture->loadFromFile(BG_PATH))
        std::cout << "Error loading background" << std::endl;

    sf::Sprite sprite(*texture);

    gCoordinator.AddComponent(background, RigidBody{
                                              sf::Vector2i(0, 0),    // position
                                              sf::Vector2f(-1, 0), // velocity
                                              sf::Vector2f(0, 0),    // acceleration
                                              sf::Vector2f(0, 0),    // bounds
                                              sf::Vector2f(0, 0),    // rotation
                                              sf::Vector2f(1, 1),    // scale
                                              false                  // hasCollision
                                          });
    gCoordinator.AddComponent(background, Drawable{
                                              texture,
                                              sprite,
                                              sf::IntRect(0, 0, BG_WIDTH, BG_HEIGHT)});
}

void initTiles()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            sf::Texture *t = new sf::Texture();
            if (!t->loadFromFile(TILE_PATH))
                std::cout << "Error loading tiles" << std::endl;

            sf::Sprite s(*t);
            Entity tile = gCoordinator.CreateEntity();

            gCoordinator.AddComponent(tile, RigidBody{
                                                sf::Vector2i(i * SIZE_TILE, j * SIZE_TILE), // position
                                                sf::Vector2f(0, 0),                         // velocity
                                                sf::Vector2f(0, 0),                         // acceleration
                                                sf::Vector2f(0, 0),                         // bounds
                                                sf::Vector2f(0, 0),                         // rotation
                                                sf::Vector2f(2, 2),                         // scale
                                                false                                       // hasCollision
                                            });
            gCoordinator.AddComponent(tile, Drawable{
                                                t,
                                                s,
                                                sf::IntRect(10 * 32, 0, 32, 32)});
            gCoordinator.AddComponent(tile, Tile{
                                                10,
                                                i,
                                                j});
        }
    }
}

void initMiner()
{
    Entity miner = gCoordinator.CreateEntity();
    gCoordinator.AddComponent(miner, Click{});
}
