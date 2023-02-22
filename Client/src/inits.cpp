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
    gCoordinator.RegisterComponent<Movement>();
    gCoordinator.RegisterComponent<Transform>();
    gCoordinator.RegisterComponent<Drawable>();
    gCoordinator.RegisterComponent<Tile>();
    gCoordinator.RegisterComponent<Click>();

    // set the signature of the systems
    Signature Msignature;
    Msignature.set(gCoordinator.GetComponentType<Movement>());
    Msignature.set(gCoordinator.GetComponentType<Transform>());
    gCoordinator.SetSystemSignature<MovementSystem>(Msignature);

    Signature Dsignature;
    Dsignature.set(gCoordinator.GetComponentType<Transform>());
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

    gCoordinator.AddComponent(background, Transform{
                                              sf::Vector2f(0, 0),
                                              sf::Vector2f(0, 0),
                                              sf::Vector2f(0, 0),
                                              sf::Vector2f(1, 1)});
    gCoordinator.AddComponent(background, Drawable{
                                              texture,
                                              sprite,
                                              sf::IntRect(0, 0, BG_WIDTH, BG_HEIGHT)});
    gCoordinator.AddComponent(background, Movement{
                                              sf::Vector2f(-0.5, 0),
                                              sf::Vector2f(0, 0)});
}

void initTiles()
{
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            sf::Texture *t = new sf::Texture();
            if (!t->loadFromFile(TILE_PATH))
                std::cout << "Error loading tiles" << std::endl;

            sf::Sprite s(*t);
            Entity tile = gCoordinator.CreateEntity();

            gCoordinator.AddComponent(tile, Transform{
                                                sf::Vector2f(i * SIZE_TILE, j * SIZE_TILE),
                                                sf::Vector2f(0, 0),
                                                sf::Vector2f(0, 0),
                                                sf::Vector2f(2, 2)});
            gCoordinator.AddComponent(tile, Drawable{
                                                t,
                                                s,
                                                sf::IntRect(10 * 32, 0, 32, 32)});
            gCoordinator.AddComponent(tile, Movement{
                                                sf::Vector2f(0, 0),
                                                sf::Vector2f(0, 0)});
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
