//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Juri Thommen on 30/05/2018.
//  Copyright © 2018 Aetherwings. All rights reserved.
//

#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

// Enums have 'global scope' within enums except strongly typed with 'class'
enum class EGuessStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame
{
public:
    
    FBullCowGame(); // constructor
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString) const;

    void Reset();
    FBullCowCount SubmitValidGuess(FString);
    
    
    
private:
    
    // see constructor for initialization
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};
