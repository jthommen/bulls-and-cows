//
//  main.cpp
//  BullCowGame
//
//  Created by Juri on 5/21/18.
//  Copyright © 2018 Aetherwings. All rights reserved.
//

#include <iostream>

using namespace std;

// function prototypes
void PrintIntro();
string GetGuessAndPrintBack();

// entry point for our application
int main() {
    
    PrintIntro();
    
    // loop for the number of turns asking for guesses
    constexpr int NUMBER_OF_TURNS  = 5;
    for(int i = 0; i < NUMBER_OF_TURNS; i++)
    {
        GetGuessAndPrintBack();
        cout << endl;
    }
    
    return 0;
}

// introduce the game
void PrintIntro()
{
    constexpr int WORD_LENGTH = 5;
    cout << "Welcome to Bulls and Cows, a fun word game." << endl;
    cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";
    return;
}

string GetGuessAndPrintBack()
{
    // get a guess from the player
    string Guess = "";
    getline(cin, Guess);
    
    // repeat the guess back
    cout << "Your guess was: " << Guess << endl;
    return Guess;
}
