/* This is the console executable, that makes use of the BullCow class
 This acts as the view in a MVC pattern, and is responsible for all user interaction.
 For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

// using unreal types
using FText = std::string;
using int32 = int;

// function prototypes as outside a class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintGameSummary();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game which we reuse across plays

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

void PrintIntro()
{
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << std::endl;
    std::cout << "          }   {         ___ " << std::endl;
    std::cout << "          (o o)        (o o) " << std::endl;
    std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
    std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
    std::cout << " *  |-,--- |              |---||-|  * " << std::endl;
    std::cout << "    ^      ^              ^      ^ " << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of? \n";
    return;
}

// plays a single game to completion
void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    // loop for the number of turns asking for guesses
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
    {
        FText Guess = GetValidGuess();
        
        // Submit valid guess to the game
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        
        // Print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
        
        std::cout << std::endl;
        
    }
    PrintGameSummary();
    return;
}

// loop continually until the user provides a valid guess
FText GetValidGuess()
{
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    FText Guess = "";
    do {
        int32 CurrentTry = BCGame.GetCurrentTry();
        
        // get a guess from the player
        std::cout << "Try " << CurrentTry << " of "<< BCGame.GetMaxTries();
        std::cout << ". Enter your guess: " << std::endl;
        getline(std::cin, Guess);
        
        // validate guess
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word!\n\n";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter an isogram (word without repeating letters)!\n\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter a all lowercase letters!\n\n";
                break;
            default:
                // repeat the guess back
                break;
        }
    } while (Status != EGuessStatus::OK); // Keep looping until we don't get any errors
    
    return Guess;
}

void PrintGameSummary()
{
    if(BCGame.IsGameWon())
    {
        std::cout << "Congratulations! You WON the game.\n";
    } else {
        std::cout << "Sorry, you LOOSE! Better luck next time.\n";
    }
    return;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again with the same word (y/n)? ";
    FText Response = "";
    getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
}
