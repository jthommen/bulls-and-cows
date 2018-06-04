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
int32 FBullCowGame::GetHiddenWordLength() const { return static_cast<int>(MyHiddenWord.length()); }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "ant";
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    
    return;
}

bool FBullCowGame::CheckGuessValidity(std::string) const
{
    return true;
}


bool FBullCowGame::IsGameWon() const
{
    return true;
}

// receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // increment the turn number
    MyCurrentTry++;
    
    // setup a return variable
    FBullCowCount BullCowCount;
    
    // loop through all letters in the guess
    int32 HiddenWordLength = static_cast<int>(MyHiddenWord.length());
    for(int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
    {
        // compare letters against the hidden word
        for(int32 GChar = 0; GChar < HiddenWordLength; GChar++)
        { // if they match then
            if(Guess[GChar] == MyHiddenWord[MHWChar])
            {
                if(MHWChar == GChar)
                { // if they're in the same place
                    BullCowCount.Bulls++; // increment the bulls
                }
                else
                {
                    BullCowCount.Cows++; // otherwise must be a cow
                }
            }
        }
    }
    
    return BullCowCount;
}
