#include <iostream>
#include <cstdlib>
#include <ctime>
#include "quickmaths.h"
using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";

void displayQuickMathsWelcome() {
    cout << MAGENTA << "Welcome to Quick Maths!" << RESET << endl;
    cout << CYAN << "Rules of the Game:" << RESET << endl;
    cout << YELLOW << "1. Choose a type of problem: Addition, Subtraction, or Multiplication." << RESET << endl;
    cout << YELLOW << "2. Solve 10 problems in the chosen category." << RESET << endl;
    cout << YELLOW << "3. You have 3 attempts for each problem." << RESET << endl;
    cout << YELLOW << "4. Points are awarded based on the number of attempts." << RESET << endl;
    cout << YELLOW << "5. Try to get the highest score possible!" << RESET << endl;
    cout << endl;
}

void addition(int counter, int &points) {
    int attempts = 0;
    int num1 = rand() % 100;
    int num2 = rand() % 100;
    int sum = num1 + num2;
    int input;

    while (attempts != 3) {
        cout << endl << num1 << " + " << num2 << " = ";
        cin >> input;
        if (input == sum) {
            cout << GREEN << "CORRECT" << RESET << endl;
            switch (attempts) {
                case 0: points += 10; break;
                case 1: points += 5; break;
                case 2: points += 2; break;
            }
            break;
        } else if (attempts != 2) {
            cout << RED << "WRONG. Try again." << RESET << endl;
        } else {
            cout << RED << "You have missed 3 times. The correct answer is " << sum << RESET << endl;
        }
        attempts++;
    }

    if (counter != 9) {
        addition(++counter, points);
    }
}

void subtraction(int counter, int &points) {
    int attempts = 0;
    int num1 = rand() % 100;
    int num2 = rand() % 100;
    int difference = num1 - num2;
    int input;

    while (attempts != 3) {
        cout << endl << num1 << " - " << num2 << " = ";
        cin >> input;
        if (input == difference) {
            cout << GREEN << "CORRECT" << RESET << endl;
            switch (attempts) {
                case 0: points += 10; break;
                case 1: points += 5; break;
                case 2: points += 2; break;
            }
            break;
        } else if (attempts != 2) {
            cout << RED << "WRONG. Try again." << RESET << endl;
        } else {
            cout << RED << "You have missed 3 times. The correct answer is " << difference << RESET << endl;
        }
        attempts++;
    }

    if (counter != 9) {
        subtraction(++counter, points);
    }
}

void multiplication(int counter, int &points) {
    int attempts = 0;
    int num1 = rand() % 100;
    int num2 = rand() % 100;
    int product = num1 * num2;
    int input;

    while (attempts != 3) {
        cout << endl << num1 << " * " << num2 << " = ";
        cin >> input;
        if (input == product) {
            cout << GREEN << "CORRECT" << RESET << endl;
            switch (attempts) {
                case 0: points += 10; break;
                case 1: points += 5; break;
                case 2: points += 2; break;
            }
            break;
        } else if (attempts != 2) {
            cout << RED << "WRONG. Try again." << RESET << endl;
        } else {
            cout << RED << "You have missed 3 times. The correct answer is " << product << RESET << endl;
        }
        attempts++;
    }

    if (counter != 9) {
        multiplication(++counter, points);
    }
}

void playQuickMathsGame() {
    displayQuickMathsWelcome();

    int userChoice;
    int counter = 0;
    int points = 0;

    cout << CYAN << "Enter the number for the desired type of problem:" << RESET << endl;
    cout << YELLOW << "\t1. Addition" << RESET << endl;
    cout << YELLOW << "\t2. Subtraction" << RESET << endl;
    cout << YELLOW << "\t3. Multiplication" << RESET << endl;
    cout << CYAN << "Enter Choice: " << RESET;
    cin >> userChoice;

    switch (userChoice) {
        case 1:
            addition(counter, points);
            break;
        case 2:
            subtraction(counter, points);
            break;
        case 3:
            multiplication(counter, points);
            break;
        default:
            cout << RED << "Invalid choice. Returning to the main menu." << RESET << endl;
            return;
    }

    cout << GREEN << endl << "Your score is: " << points << RESET << endl;
}
