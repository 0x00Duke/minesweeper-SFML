/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** initGrid.cpp
*/

#include <iostream>
#include <vector>

#include "inRange.cpp"

using namespace std;
using IntVector = std::vector<int>;
using IntMatrix = std::vector<IntVector>;

template <typename T>
bool inRange(T value, T min, T max);

int getValue(IntMatrix grid, int i, int j)
{
    int n = 0;

    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            int ni = i + di;
            int nj = j + dj;
            if (inRange(ni, 1, 10) && inRange(nj, 1, 10) && grid[ni][nj] == 9) {
                n++;
            }
        }
    }
    return n;
}

IntMatrix initGrid()
{
    IntMatrix grid(12, std::vector<int>(12));

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            grid[i][j] = (!(rand() % 5) ? 9 : 0);

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (grid[i][j] == 9) continue;
            grid[i][j] = getValue(grid, i, j);
        }
    }
    return grid;
}
