#include <iostream>
#include <string>
#include <cstdlib>
#include "hangman.h"
using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

void displayHangmanWelcome() {
    cout << MAGENTA << "Welcome to Hangman!" << RESET << endl;
    cout << CYAN << "Rules of the Game:" << RESET << endl;
    cout << YELLOW << "1. One player sets a word for the other player to guess." << RESET << endl;
    cout << YELLOW << "2. The other player guesses letters or the whole word." << RESET << endl;
    cout << YELLOW << "3. If the guessed letter is in the word, it will be revealed." << RESET << endl;
    cout << YELLOW << "4. If the guessed letter is not in the word, it will be recorded as incorrect." << RESET << endl;
    cout << YELLOW << "5. The player can guess the whole word at any time by entering '$' followed by the word." << RESET << endl;
    cout << YELLOW << "6. The game ends when the word is guessed correctly or all letters are revealed." << RESET << endl;
    cout << YELLOW << "7. Enjoy the game and good luck!" << RESET << endl;
    cout << endl;
}

void guess(string word, string hiddenWord, int length) {
    char guess;
    int numOfGuess = 0;
    string guessWord;
    char guessedLetters[1000];
    int counter = 0;

    while(hiddenWord != word) {
        bool isRight = false;

        if ((word != hiddenWord) || (word != guessWord)) {
            cout << CYAN << "\nYour letter ($ to guess the word)? " << RESET;
            cin >> guess;
        }

        numOfGuess++;
        bool alreadyGuessed = false;

        for(int check = 0; check < counter; check++) {
            if(guess == guessedLetters[check]) {
                alreadyGuessed = true;
                cout << RED << "Sorry, you guessed " << guess << " already. Try Again.\n" << RESET;
                break;
            }
        }
        if (!alreadyGuessed) {
            for(int i = 0; i < length; i++) {
                for (int i = 0; i < length; i++) {
                    if (guess == word[i]){
                        isRight = true;
                        guessedLetters[counter] = guess;
                        counter++;
                    }
                }
                if(word[i] == guess) {
                    hiddenWord[i] = guess;
                } else if(guess == '$') {
                    cout << CYAN << "Your guess? " << RESET;
                    cin >> guessWord;
                    if(guessWord == word) {
                        cout << GREEN << "\nCORRECT! You took " << numOfGuess << " tries." << RESET;
                        break;
                    } else if (guessWord != word) {
                        break;
                    }
                } else {
                    if(!isRight) {
                        guessedLetters[counter] = guess;
                        counter++;
                        cout << RED << "Sorry, there are no " << guess << "'s" << RESET << endl;
                        break;
                    }
                }
            }
        }
        if (guessWord == word) {
            break;
        }
        if (word == hiddenWord) {
            cout << GREEN << "\nCORRECT! You took " << numOfGuess << " tries." << RESET;
            break;
        } else if (guessWord != word) {
            cout << YELLOW << "Word is " << hiddenWord << RESET << endl;
        }
    }
}

void word() {
    string word;
    cout << CYAN << "Please enter a word to be guessed: " << RESET;
    cin >> word;
    if (system("clear") == 1) {}

    cout << YELLOW << "Word is ";
    int length = word.length();
    string hiddenWord = word;
    for(int i = 0; i < length; i++) {
        hiddenWord[i] = '-';
    }
    cout << hiddenWord << RESET;
    guess(word, hiddenWord, length);
}

void playHangmanGame() {
    displayHangmanWelcome();

    do {
        word(); // starts game

        char playAgain;
        cout << CYAN << endl << "Do you want to play again? (Y/N): " << RESET;
        cin >> playAgain;
        if (playAgain == 'Y' || playAgain == 'y') {
            if (system("clear") == 1) {}
        } else {
            break;
        }
    } while (true);
}
