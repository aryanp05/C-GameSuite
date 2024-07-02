#include <iostream>
#include <cstdlib>
#include "21cards.h"
using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

void display21CardsWelcome() {
    cout << MAGENTA << "Welcome to the 21 Cards Game!" << RESET << endl;
    cout << CYAN << "Rules of the Game:" << RESET << endl;
    cout << YELLOW << "1. You and the computer will draw cards with values between 1 and 10." << RESET << endl;
    cout << YELLOW << "2. You will decide how many cards you want to draw, up to a maximum of 10." << RESET << endl;
    cout << YELLOW << "3. The computer will always draw 3 cards." << RESET << endl;
    cout << YELLOW << "4. The goal is to have a total card value as close to 21 as possible without exceeding it." << RESET << endl;
    cout << YELLOW << "5. If both you and the computer exceed 21, the round is a draw." << RESET << endl;
    cout << YELLOW << "6. If your total is closer to 21 than the computer's, you win the round." << RESET << endl;
    cout << YELLOW << "7. If the computer's total is closer to 21 than yours, the computer wins the round." << RESET << endl;
    cout << YELLOW << "8. Enjoy the game and good luck!" << RESET << endl;
    cout << endl;
    void play21CardsGame();
}

void draw(int &drawedCard) {
    drawedCard = (rand() % 10) + 1;
}

void playSingleRound21Cards(int &compWins, int &playerWins, int &gameDraws) {
    if (system("clear") == 1) {}
    display21CardsWelcome(); // Add this line
    int cardNum, drawedCard, playerTotal = 0, compTotal = 0;

    cout << CYAN << "How many cards do you want? " << RESET;
    cin >> cardNum;
    int computerCards[3], playerCards[cardNum];
    char outcome = 0;

    for(int i = 0; i < 3; i++) {
        draw(drawedCard);
        computerCards[i] = drawedCard;
    }

    for(int i = 0; i < cardNum; i++) {
        draw(drawedCard);
        playerCards[i] = drawedCard;
    }

    cout << GREEN << "You: " << RESET;
    for(int i = 0; i < cardNum; i++) {
        cout << playerCards[i] << "  ";
    }

    cout << BLUE << "\nComputer: " << RESET;
    for(int i = 0; i < 3; i++) {
        cout << computerCards[i] << "  ";
    }

    for(int i = 0; i < 3; i++) {
        compTotal += computerCards[i];
    }

    for(int i = 0; i < cardNum; i++) {
        playerTotal += playerCards[i];
    }

    if(playerTotal > compTotal && playerTotal <= 21) {
        outcome = 1;
    } else if(playerTotal <= 21 && compTotal > 21) {
        outcome = 1;
    } else if(playerTotal == compTotal) {
        outcome = 2;
    } else if(playerTotal > 21 && compTotal > 21) {
        outcome = 2;
    } else if(compTotal > playerTotal && compTotal <= 21) {
        outcome = 3;
    } else if(compTotal <= 21 && playerTotal > 21) {
        outcome = 3;
    }

    cout << YELLOW << "\nI have " << compTotal << " and you have " << playerTotal << " so ";

    switch(outcome) {
        case 1:
            cout << GREEN << "you win!" << RESET;
            playerWins++;
            break;
        case 2:
            cout << CYAN << "we draw." << RESET;
            gameDraws++;
            break;
        case 3:
            cout << RED << "I win." << RESET;
            compWins++;
            break;
        default:
            cout << RED << "an unexpected error occurred." << RESET;
            break;
    }
}

void play21CardsGame() {
    int compWins = 0, playerWins = 0, gameDraws = 0;
    char playAgain;

    do {
        playSingleRound21Cards(compWins, playerWins, gameDraws);

        cout << CYAN << "\nDo you want to play again? (Y/N): " << RESET;
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << BLUE << "Computer wins = " << compWins << endl; 
    cout << GREEN << "Your wins = " << playerWins << endl;
    cout << CYAN << "Draws = " << gameDraws << endl << RESET;
}
