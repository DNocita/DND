//
//  Character.cpp
//  DNDApp
//
//  Created by Diodato Nocita on 2019-04-05.
//  Copyright © 2019 Diodato Nocita. All rights reserved.
//

#include "Character.hpp"
#include "../Race/Race.hpp"

Character:: Character () {
    
    
};

Character :: ~Character () {
    
};

Character::Character (Race * race) {
    Calculate(race);
}

void Character::Calculate() {
    
    
}

void Character::Calculate(Race * race) {
    setStatTotals(race);
    setBonus();
    
    setSaveBool(race);
    setSaveBonus();
    
    setSkillBool(race);
    setSkillBonus();
    setIniBonus();
}




// set Functions
void Character::setRoll(int n,int value) {
    this->Rolls[n] = value;
};

void Character::setStatTotal(int n,int value) {
    this->StatTotal[n] = value;
};


void Character::setStatTotals(Race * race) {
    int *pRace = race->getRace_Bonus();
    int *pSubRace = race->getSubRace_Bonus();
    
    for (int i=0;i<6;i++) {
        int temp =0;
        
        temp= pRace[i]+ pSubRace[i] + this->Rolls[i];
        
        if (temp>=20) {
            setStatTotal(i,20);
        } else {
            setStatTotal(i,temp);
        }        
    }
};

void Character::setBonus() {
    for (int i=0;i<6;i++) {
        Bonus[i] = CalcBonus(getStatTotal(i));
    }
};

void Character::setSaveBonus(){
    
    for (int i=0;i<6;i++) {
        SaveBool[i]!=0 ? SaveBonus[i] = Bonus[i] + PROF : SaveBonus[i]= Bonus[i];
    }
};

void Character::setSaveBool(Race * race) {
    int *pRaceSave = race->getSaveBool();
    for (int i=0; i<6; i++) {
        SaveBool[i]+=pRaceSave[i];
    }
};

void Character::setSkillBool(Race * race) {
    int *pRaceSkill = race->getSkillBool();
    for (int i=0;i<18; i++) {
        SkillBool[i]+=pRaceSkill[i];
    }
}

void Character::setSkillBonus(){
    for (int i=0;i<18; i++) {
        //skill bonus list
        if (i==3) {
            SkillBonus[i]+=Bonus[0]; // Strength
        } else if (i==0||i==15||i==16) {
            SkillBonus[i]+=Bonus[1]; // Dexterity
        } else if (i==2||i==5||i==8||i==10||i==14) {
            SkillBonus[i]+=Bonus[3]; // Intelligence
        } else if (i==1||i==6||i==9||i==11||i==17) {
            SkillBonus[i]+=Bonus[4]; // Widsom
        } else if (i==4||i==7||i==12||i==13) {
            SkillBonus[i]+=Bonus[5]; // Charisma
        } else {
            // Constitution
        }
        
        
        if(SkillBool[i] !=0) {
            SkillBonus[i]+=PROF; // add proficiency if proficient
        }
    }
}
void Character::setIniBonus(){
    Ini+=Bonus[1];
}



// Get functions
int * Character::getStatTotals() {
    return this->StatTotal;
};
int Character::getStatTotal(int n) {
    return StatTotal[n];
}

int * Character::getRolls() {
    return this->Rolls;
};

int * Character::getBonus() {
    return this->Bonus;
};

int * Character::getSaveBonus()
{
    return this->SaveBonus;
}

int * Character:: getSkillBonus() {
    return this->SkillBonus;
}

int Character:: getIniBonus() {
    return this->Ini;
}



//class functions
int Character::CalcBonus(int n) {
    if (n>=20) {
        return 5;
    } else if (n==19||n==18) {
        return 4;
    } else if (n==17||n==16) {
        return 3;
    } else if (n==15||n==14) {
        return 2;
    } else if (n==13||n==12) {
        return 1;
    }else if (n==11||n==10) {
        return 0;
    } else if (n==9||n==8) {
        return -1;
    }else if (n==7||n==6) {
        return -2;
    } else if (n==5||n==4) {
        return -3;
    }else if (n==3||n==2) {
        return -4;
    }
    return -5;
}
