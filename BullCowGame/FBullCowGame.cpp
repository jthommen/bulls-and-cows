//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Juri Thommen on 30/05/2018.
//  Copyright © 2018 Aetherwings. All rights reserved.
//

#include "FBullCowGame.hpp"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    
    return;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
    return true;
}


bool FBullCowGame::IsGameWon() const
{
    return true;
}

// receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
    // increment the turn number
    MyCurrentTry++;
    
    // setup a return variable
    FBullCowCount BullCowCount;
    
    // loop through all letters in the guess
    int32 HiddenWordLength = MyHiddenWord.length();
    for(int32 i = 0; i < HiddenWordLength; i++)
    {
        // compare letters against the hidden word
        for(int32 j = 0; j < HiddenWordLength; j++)
        {
            
        }
            // if they match then
                // increment bulls if they're in the same place
                // increment cows if not
    }
    
    return BullCowCount;
}

