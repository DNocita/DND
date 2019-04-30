//
//  Character.hpp
//  DNDApp
//
//  Created by Diodato Nocita on 2019-04-05.
//  Copyright © 2019 Diodato Nocita. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include "../main.hpp"
#include "../Race/Race.hpp"

class Character {
public:
    Character (); // Constructor for no input object creation
    ~Character ();
    Character(Race *); // Overloaded object creation
    
    void Calculate(); // Calculates values based on current saved info
    void Calculate(Race *); // Calculates values based on complete Character info
    
    
    void setStatTotals(Race *);
    void setRoll(int,int);
    void setStatTotal(int,int);
    void setBonus();
    void setSaveBonus();
    void setSaveBool(Race *);
    void setSkillBool(Race *);
    void setSkillBonus();
    void setIniBonus();
    
    
    int * getRolls();
    int * getStatTotals();
    int getStatTotal(int n);
    int * getBonus();
    int * getSaveBonus();
    int * getSkillBonus();
    int getIniBonus();
    
    int CalcBonus(int); // Calculates what stat bonus should be
    
    
    
protected:
    static const int PROF = 1;
    int Ini=0;
    
    int Bonus[6]={}; // Array for Bonus Values
    int Rolls[6]={14,12,12,18,5,6}; // Array for Roll values
    int StatTotal[6]={}; // Array for Total Stat values
    
    int SaveBool[6]={}; // will denote proficiency for saving throws
    int SaveBonus[6]={}; // Array for calculated saving throws based on bonus and proficiency
    
    int SkillBool[18]={};
    int SkillBonus[18]={};
};




#endif /* Character_hpp */
