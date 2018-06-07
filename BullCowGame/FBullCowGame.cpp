//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Juri Thommen on 30/05/2018.
//  Copyright © 2018 Aetherwings. All rights reserved.
//
#pragma once

#include "FBullCowGame.hpp"
#include <map>

// to make syntax more Unreal friendly
#define TMap std::map
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // default constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return static_cast<int>(MyHiddenWord.length()); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const {
    TMap<int32, int32> WordLengthToMaxTries { {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
    return WordLengthToMaxTries[static_cast<int>(MyHiddenWord.length())];
}

void FBullCowGame::Reset()
{
    bGameIsWon = false;
    MyCurrentTry = 1;
    
    const FString HIDDEN_WORD = "chores"; // this must be an isogram
    MyHiddenWord = HIDDEN_WORD;
    
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if(!IsIsogram(Guess))
    {
        return EGuessStatus::Not_Isogram;
    }
    else if(!IsLowercase(Guess))
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if(GetHiddenWordLength() != Guess.length())
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
    
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
    
    if(BullCowCount.Bulls == WordLength) { bGameIsWon = true; }
    
    return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const {
    
    // treat 0 and 1 letter words as isograms
    if (Guess.length() <= 1) { return true; }
     
    TMap<char, bool> LetterSeen;// setup our map
    for(auto Letter : Guess) // for all letters of the guess
    {
        Letter = tolower(Letter); // handle mixed case
        if(LetterSeen[Letter]) // if the letter is in the map
        {
           return false; // we don't have an isogram
        }
        else
        {
            LetterSeen[Letter] = true; // add letter to the map
        }
    }
    return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const {
    
    if(Guess.length() == 0 )
    { return false; }
    
    for(auto Letter : Guess)
    {
        if(!islower(Letter)) { return false; }
    }
    return true;
}
