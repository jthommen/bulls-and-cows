//
//  main.cpp
//  BullCowGame
//
//  Created by Juri on 5/21/18.
//  Copyright © 2018 Aetherwings. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

// function prototypes
void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate

// entry point for our application
int main() {
    do {
        PrintIntro();
        PlayGame();
        std::cout << std::endl;
    } while (AskToPlayAgain());

    std::cout << "Sorry to see you leave, come back soon!\n";
    return 0; // exit the application
}

// introduce the game
void PrintIntro()
{
    constexpr int WORD_LENGTH = 5;
    std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int MaxTries = BCGame.GetMaxTries();
    
    // loop for the number of turns asking for guesses
    // TODO: change from FOR to WHILE loop once we are validating tries
    for(int i = 0; i < MaxTries; i++)
    {
        std::string Guess = GetGuess(); // TODO: make loop check validity of guesses
        
        // Submit valid guess to the game
        // Print number of bulls and cows
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }
    // TODO: summarize game
    return;
}

std::string GetGuess()
{
    int CurrentTry = BCGame.GetCurrentTry();
    
    // get a guess from the player
    std::cout << "Try " << CurrentTry << ". Enter your guess: " << std::endl;
    
    std::string Guess = "";
    getline(std::cin, Guess);
    
    // repeat the guess back
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? ";
    std::string Response = "";
    getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
}
