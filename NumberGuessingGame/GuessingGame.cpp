#include "GuessingGame.h"
#include <ctime>
#include <iostream>

GuessingGame::GuessingGame() {
    shouldRestart = false;
    remainingGuesses = 3;
}

void GuessingGame::startGame(int lowerBound, int upperBound) {
    srand(time(0));
    secret = rand() % (upperBound - lowerBound + 1) + lowerBound;
    remainingGuesses = 3;
    shouldRestart = false;
    std::cout << "Game started! Enter a guess." << std::endl;
}

std::string GuessingGame::submitGuess(int guess) {
    if (guess == secret) {
        shouldRestart = true;
        return "You Won!";
    }
    else {
        remainingGuesses--;
        if (remainingGuesses <= 0) {
            shouldRestart = true;
            return "You Lost. The correct number was " + std::to_string(secret) + ".";
        }
        else {
            return "Incorrect guess. Remaining guesses: " + std::to_string(remainingGuesses);
        }
    }
}

bool GuessingGame::isGameOver() {
    return shouldRestart;
}