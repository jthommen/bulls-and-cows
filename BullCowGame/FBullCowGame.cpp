//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Juri Thommen on 30/05/2018.
//  Copyright © 2018 Aetherwings. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() { Reset(); }

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
    constexpr int MAX_TRIES = 8;
    
    MyMaxTries = MAX_TRIES;
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
