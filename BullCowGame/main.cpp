//
//  main.cpp
//  BullCowGame
//
//  Created by Juri on 5/21/18.
//  Copyright © 2018 Aetherwings. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// function prototypes
void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

// entry point for our application
int main() {
    do {
        PrintIntro();
        PlayGame();
        cout << endl;
    } while (AskToPlayAgain());

    cout << "Sorry to see you leave, come back soon!\n";
    return 0; // exit the application
}

// introduce the game
void PrintIntro()
{
    constexpr int WORD_LENGTH = 5;
    cout << "Welcome to Bulls and Cows, a fun word game." << endl;
    cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";
    return;
}

void PlayGame()
{
    // loop for the number of turns asking for guesses
    constexpr int NUMBER_OF_TURNS  = 5;
    for(int i = 0; i < NUMBER_OF_TURNS; i++)
    {
        cout << "Your guess was: " << GetGuess() << endl;
        cout << endl;
    }
    return;
}

string GetGuess()
{
    // get a guess from the player
    string Guess = "";
    getline(cin, Guess);
    
    // repeat the guess back
    return Guess;
}

bool AskToPlayAgain()
{
    cout << "Do you want to play again? ";
    string Response = "";
    getline(cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
}
