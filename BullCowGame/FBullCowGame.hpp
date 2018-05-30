//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Juri Thommen on 30/05/2018.
//  Copyright © 2018 Aetherwings. All rights reserved.
//

#pragma once
#include <string>

class FBullCowGame {
public:
    
    FBullCowGame(); // constructor
    
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset();
    bool CheckGuessValidity(std::string);
    // provide method for counting bulls and cows & incrementing turn number
    
    
    
private:
    
    // see constructor for initialization
    int MyCurrentTry;
    int MyMaxTries;
};
