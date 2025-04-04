#pragma once
#include <string>

class GuessingGame {
private:
    int secret;
    int remainingGuesses;
    bool shouldRestart;

public:
    GuessingGame();
    void startGame(int lowerBound, int upperBound);
    std::string submitGuess(int guess);
    bool isGameOver();
};
