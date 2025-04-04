#include <iostream>
#include "GuessingGame.h"

int main() {
    int lowerBound, upperBound, guess;
    GuessingGame game;

    std::cout << "Enter lower bound: ";
    std::cin >> lowerBound;
    std::cout << "Enter upper bound: ";
    std::cin >> upperBound;

    game.startGame(lowerBound, upperBound);

    while (!game.isGameOver()) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        std::cout << game.submitGuess(guess) << std::endl;
    }

    std::cout << "Game over. Restart the program to play again." << std::endl;
    return 0;
}
