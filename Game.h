#pragma once
#include "Match.h"
#include <iostream>
#include <conio.h>
using namespace std;

class Game
{
private:
    Match match;
public:
    void menu();
    void play();
    void instruct();
    void save();
    void showHistory();
};

void Game::menu()
{
    char option;
    do
    {
        system("cls");
        cout << "____________CARO GAME_______________\n";
        cout << "1. Play\n";
        cout << "2. How to play\n";
        cout << "3. History\n";
        cout << "4. Exit\n";
        cout << "____________________________________\n";
        option = getch();
        switch (option)
        {
            case '1': play(); break;
            case '2': instruct(); break;
            case '3': showHistory(); break;
        }
    } while (option != '4');
}

void Game::play()
{
    cout << "Enter size of the board: ";
    int size;
    cin >> size;
    match = Match(size);

    match.play();

    cout << "Do you want to save game? (y/n)\n";
    char option;
    if (option == 'y' || option == 'Y')
        save();
}

void Game::instruct()
{
    cout << "Match 5 to win!\n";
}

void Game::showHistory()
{
    // Place holder
}

void Game::save() {
    // Place holder
}