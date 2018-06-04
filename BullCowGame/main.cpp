/* This is the console executable, that makes use of the BullCow class
 This acts as the view in a MVC pattern, and is responsible for all user interaction.
 For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

// using unreal types
using FText = std::string;
using int32 = int;

// function prototypes
void PrintIntro();
void PlayGame();
FText GetGuess();
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
    std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of? \n";
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    // loop for the number of turns asking for guesses
    // TODO: change from FOR to WHILE loop once we are validating tries
    for(int32 i = 0; i < MaxTries; i++)
    {
        FText Guess = GetGuess(); // TODO: make loop check validity of guesses
        
        // Submit valid guess to the game
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        
        // Print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
        
        std::cout << std::endl;
        
    }
    // TODO: summarize game
    return;
}

FText GetGuess()
{
    int32 CurrentTry = BCGame.GetCurrentTry();
    
    // get a guess from the player
    std::cout << "Try " << CurrentTry << ". Enter your guess: " << std::endl;
    
    FText Guess = "";
    getline(std::cin, Guess);
    
    // repeat the guess back
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? ";
    FText Response = "";
    getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
}
