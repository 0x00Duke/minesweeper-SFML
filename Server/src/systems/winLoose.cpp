/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** winLoose.hpp
*/

#include "../../include/systems/winLoose.hpp"

extern eecsge::Coordinator gCoordinator;

bool WinLooseSystem::check()
{
    for (auto const &entity : mEntities) {
        auto &tile = gCoordinator.GetComponent<Tile>(entity);
        if (tile.sValue == 9) {
            std::string send_message = "loose";

            eecsge::Event newEvent(Events::EndGame::ENDGAME);
            newEvent.SetParam(Events::EndGame::EndGame::status, send_message);
            gCoordinator.SendEvent(newEvent);
            return true;
        }
    }
    return false;
}

bool WinLooseSystem::CheckWin()
{
    for (auto const &entity : mEntities) {
        auto &tile = gCoordinator.GetComponent<Tile>(entity);
        if (tile.sValue != tile.value && tile.sValue != 11)
            return false;
    }

    std::string send_message = "win";

    eecsge::Event newEvent(Events::EndGame::ENDGAME);
    newEvent.SetParam(Events::EndGame::EndGame::status, send_message);
    gCoordinator.SendEvent(newEvent);
    return true;
}

bool WinLooseSystem::CheckLoose()
{
    return (CheckLoose() || CheckWin());
}
