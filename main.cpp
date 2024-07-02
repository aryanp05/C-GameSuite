#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hangman.h"
#include "21cards.h"
#include "dicegame.h"
#include "quickmaths.h"
using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

void displayMenu() {
  if (system("clear") == 1) {}
    cout << MAGENTA << "Welcome to the Game Center!" << RESET << endl;
    cout << YELLOW << "Choose a game to play:" << RESET << endl;
    cout << CYAN << "1. Hangman" << RESET << endl;
    cout << CYAN << "2. 21 Cards" << RESET << endl;
    cout << CYAN << "3. Dice Game" << RESET << endl;
    cout << CYAN << "4. Quick Maths" << RESET << endl;
    cout << RED << "5. Exit" << RESET << endl;
}

int main() {
    srand(time(0)); // Seed the random number generator

    char choice;
    bool exit = false;

    while (!exit) {
        displayMenu();
        cout << GREEN << "Enter your choice: " << RESET;
        cin >> choice;

        switch(choice) {
            case '1':
                playHangmanGame();
                break;
            case '2':
                play21CardsGame();
                break;
            case '3':
                playDiceGame();
                break;
            case '4':
                playQuickMathsGame();
                break;
            case '5':
                exit = true;
                cout << RED << "Thank you for playing! Goodbye!" << RESET << endl;
                break;
            default:
                cout << RED << "Invalid choice. Please try again." << RESET << endl;
        }
    }

    return 0;
}
