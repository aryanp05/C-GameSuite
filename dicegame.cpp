#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dicegame.h"
using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";

void displayDiceGameWelcome() {
    cout << YELLOW << "Welcome to the Dice Game!" << RESET << endl;
    cout << CYAN << "Rules of the Game:" << RESET << endl;
    cout << YELLOW << "1. Roll two dice." << RESET << endl;
    cout << YELLOW << "2. Bet points on whether the sum of the dice will be even or odd." << RESET << endl;
    cout << YELLOW << "3. Double your bet if you win; lose your bet if you lose." << RESET << endl;
    cout << YELLOW << "4. You start with 1000 points. Game ends when you have 0 points or choose to exit." << RESET << endl;
    cout << endl;
}

void runGame(int &points) {
    cout << CYAN << "You have " << points << " points." << RESET << endl;

    if (points > 0) {
        int pointsBet;
        cout << YELLOW << "Points to bet: " << RESET;
        cin >> pointsBet;

        if (pointsBet > points) {
            cout << RED << "You don't have enough points to bet that amount. Please try again." << RESET << endl;
            runGame(points);
            return;
        }

        points -= pointsBet;

        int diceOne = (rand() % 6) + 1;
        int diceTwo = (rand() % 6) + 1;
        int diceTotal = diceOne + diceTwo;

        cout << "Roll is " << diceOne << " and " << diceTwo << "." << endl;

        if (diceTotal % 2 == 0) {
            points += pointsBet * 2;
            cout << GREEN << "You win!" << RESET << endl;
        } else {
            cout << RED << "You lose!" << RESET << endl;
        }

        char playAgain;
        cout << CYAN << "Play Again? (Y/N): " << RESET;
        cin >> playAgain;

        if (playAgain == 'Y' || playAgain == 'y') {
            runGame(points);
        } else {
            cout << "Final Score: " << points << " points." << endl;
        }
    } else {
        cout << RED << "You don't have any points left to play." << RESET << endl;
    }
}

void playDiceGame() {
    displayDiceGameWelcome();
    int points = 1000;
    runGame(points);
}
