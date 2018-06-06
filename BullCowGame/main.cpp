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
FText GetValidGuess();
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
    for(int32 i = 0; i < MaxTries; i++) // TODO: change from FOR to WHILE loop once we are validating tries
    {
        FText Guess = GetValidGuess();
        
        // Submit valid guess to the game
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        
        // Print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
        
        std::cout << std::endl;
        
    }
    // TODO: summarize game
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
        std::cout << "Try " << CurrentTry << ". Enter your guess: " << std::endl;
        getline(std::cin, Guess);
        
        // validate guess
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word!";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter an isogram (word without repeating letters)!";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter a all lowercase letters!";
                break;
            default:
                // repeat the guess back
                break;
        }
        std::cout << std::endl;
    } while (Status != EGuessStatus::OK); // Keep looping until we don't get any errors
    
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? ";
    FText Response = "";
    getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
}
