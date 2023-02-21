/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** init.cpp
*/

#include "include/init.hpp"

extern Coordinator gCoordinator;

void initBackground()
{
    Entity background = gCoordinator.CreateEntity();
    sf::Texture *texture = new sf::Texture();

    if (!texture->loadFromFile("images/bg.jpg"))
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
                                              sf::IntRect(0, 0, 5149, 3433)});
    gCoordinator.AddComponent(background, Movement{
                                              sf::Vector2f(-0.5, 0),
                                              sf::Vector2f(0, 0)});
}

void initSignatures()
{
    // register the components to the coordinator
    gCoordinator.RegisterComponent<Movement>();
    gCoordinator.RegisterComponent<Transform>();
    gCoordinator.RegisterComponent<InputKeys>();
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

    Signature signatureMiner;
    // signatureMiner.set(gCoordinator.GetComponentType<InputKeys>());
    // signatureMiner.set(gCoordinator.GetComponentType<Movement>());
    // signatureMiner.set(gCoordinator.GetComponentType<Transform>());
    signatureMiner.set(gCoordinator.GetComponentType<Click>());
    gCoordinator.SetSystemSignature<MinerSystem>(signatureMiner);

    Signature signatureBackground;
    signatureBackground.set(gCoordinator.GetComponentType<Drawable>());
    gCoordinator.SetSystemSignature<newBackgroundSystem>(signatureBackground);

    Signature signatureMap;
    signatureMap.set(gCoordinator.GetComponentType<Drawable>());
    signatureMap.set(gCoordinator.GetComponentType<Tile>());
    gCoordinator.SetSystemSignature<MapSystem>(signatureMap);

    Signature signatureWinLoose;
    signatureWinLoose.set(gCoordinator.GetComponentType<Tile>());
    gCoordinator.SetSystemSignature<WinLooseSystem>(signatureWinLoose);
}

void initMap()
{
    int grid[12][12];
    int sgrid[12][12]; // for showing

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            sgrid[i][j] = 10;
            if (rand() % 5 == 0)
                grid[i][j] = 9;
            else
                grid[i][j] = 0;
        }
    }

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            int n = 0;
            if (grid[i][j] == 9)
                continue;
            if (grid[i + 1][j] == 9)
                n++;
            if (grid[i][j + 1] == 9)
                n++;
            if (grid[i - 1][j] == 9)
                n++;
            if (grid[i][j - 1] == 9)
                n++;
            if (grid[i + 1][j + 1] == 9)
                n++;
            if (grid[i - 1][j - 1] == 9)
                n++;
            if (grid[i - 1][j + 1] == 9)
                n++;
            if (grid[i + 1][j - 1] == 9)
                n++;
            grid[i][j] = n;
        }
    }

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            sf::Texture *t = new sf::Texture();
            if (!t->loadFromFile("images/tiles.jpg"))
                std::cout << "Error loading tiles" << std::endl;
            sf::Sprite s(*t);
            Entity tile = gCoordinator.CreateEntity();
            gCoordinator.AddComponent(tile, Transform{
                                                sf::Vector2f(i * 32, j * 32),
                                                sf::Vector2f(0, 0),
                                                sf::Vector2f(0, 0),
                                                sf::Vector2f(1, 1)});
            gCoordinator.AddComponent(tile, Drawable{
                                                t,
                                                s,
                                                sf::IntRect(sgrid[i][j] * 32, 0, 32, 32)});
            gCoordinator.AddComponent(tile, Movement{
                                                sf::Vector2f(0, 0),
                                                sf::Vector2f(0, 0)});
            gCoordinator.AddComponent(tile, Tile{
                                                grid[i][j],
                                                sgrid[i][j],
                                                i,
                                                j});
        }
    }
}