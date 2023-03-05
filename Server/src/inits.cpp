/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** inits.cpp
*/

#include "../include/inits.hpp"

extern eecsge::Coordinator gCoordinator;

void initSignatures()
{
    gCoordinator.RegisterComponent<Tile>();
    gCoordinator.RegisterComponent<Client>();

    eecsge::Signature signatureMap;
    signatureMap.set(gCoordinator.GetComponentType<Tile>());
    gCoordinator.SetSystemSignature<MapSystem>(signatureMap);

    eecsge::Signature signatureClients;
    signatureClients.set(gCoordinator.GetComponentType<Client>());
    gCoordinator.SetSystemSignature<ClientsSystem>(signatureClients);
}

void initTiles()
{
    int sgrid[12][12] = {};
    std::vector<std::vector<int>> grid = initGrid();

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            eecsge::Entity tile = gCoordinator.CreateEntity();
            gCoordinator.AddComponent(tile, Tile{
                                                grid[i][j],
                                                sgrid[i][j],
                                                i,
                                                j});
        }
    }
}
