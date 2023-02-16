/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** game.cpp
*/

#include "../include/game.hpp"
#include "../include/systems/miner.hpp"
#include "../include/systems/background.hpp"

Coordinator gCoordinator;

Game::Game()
{
    gCoordinator.Init();
}

Game::~Game()
{
}

void initBackground()
{
    Entity background = gCoordinator.CreateEntity();
    sf::Texture *texture = new sf::Texture();

    if (!texture->loadFromFile("images/bg.jpg"))
        std::cout << "Error loading background" << std::endl;

    sf::Sprite sprite(*texture);

    gCoordinator.AddComponent(background, Transform{
                                              .position = sf::Vector2f(0, 0),
                                              .scale = sf::Vector2f(1, 1)});

    gCoordinator.AddComponent(background, Drawable{
                                              .sprite = sprite,
                                              .texture = texture});
    gCoordinator.AddComponent(background, Movement{
                                              .velocity = sf::Vector2f(-0.5, 0),
                                              .acceleration = sf::Vector2f(0, 0)});
}

void initSignatures()
{
    // register the components to the coordinator
    gCoordinator.RegisterComponent<Movement>();
    gCoordinator.RegisterComponent<Transform>();
    gCoordinator.RegisterComponent<InputKeys>();
    gCoordinator.RegisterComponent<Drawable>();

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
    signatureMiner.set(gCoordinator.GetComponentType<InputKeys>());
    signatureMiner.set(gCoordinator.GetComponentType<Movement>());
    signatureMiner.set(gCoordinator.GetComponentType<Transform>());
    gCoordinator.SetSystemSignature<MinerSystem>(signatureMiner);

    Signature signatureBackground;
    signatureBackground.set(gCoordinator.GetComponentType<Drawable>());
    gCoordinator.SetSystemSignature<newBackgroundSystem>(signatureBackground);

    // Signature signatureMap;
    // signatureMap.set(gCoordinator.GetComponentType<Drawable>());
    // gCoordinator.SetSystemSignature<MapSystem>(signatureMap);
}

void Game::run()
{
    auto minerSystem = gCoordinator.RegisterSystem<MinerSystem>();
    auto drawSystem = gCoordinator.RegisterSystem<DrawSystem>();
    auto movementSystem = gCoordinator.RegisterSystem<MovementSystem>();
    auto backgroundSystem = gCoordinator.RegisterSystem<newBackgroundSystem>();
    // auto mapSystem = gCoordinator.RegisterSystem<MapSystem>();

    initSignatures();

    // create the window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Minesweeper");

    // create the background
    initBackground();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        // playerSystem->update(event);
        // movementSystem->update(event);
        backgroundSystem->update(event);
        // mapSystem->update(event);

        window.clear();
        drawSystem->DrawEntities(&window);
        window.display();
    }
}
