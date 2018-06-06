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
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if(false)// if the guess isn't an isogram
    {
        return EGuessStatus::Not_Isogram;
    } else if(false) // if the guess isn't all lowercase

    {
        return EGuessStatus::Not_Lowercase;
    } else if(GetHiddenWordLength() != Guess.length())
    {
        return EGuessStatus::Wrong_Length;
    } else
    {
        return EGuessStatus::OK;
    }
    
}


bool FBullCowGame::IsGameWon() const
{
    return true;
}

// receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    
    // loop through all letters in the hidden word
    int32 WordLength = static_cast<int>(MyHiddenWord.length()); // assuming same length as guess
    for(int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
    {
        // compare letters against the guess
        for(int32 GChar = 0; GChar < WordLength; GChar++)
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
