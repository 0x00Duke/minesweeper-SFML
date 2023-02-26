/*
** EPITECH PROJECT, 2022
** minesweeper-SFML
** File description:
** inRange.cpp
*/

template <typename T>
bool inRange(T value, T min, T max) {
    return (value >= min) && (value <= max);
}
