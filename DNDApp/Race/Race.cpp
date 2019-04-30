//
//  Race.cpp
//  DNDApp
//
//  Created by Diodato Nocita on 2019-04-04.
//  Copyright © 2019 Diodato Nocita. All rights reserved.
//

#include "Race.hpp"

Race::Race(){
    this->speed=5;
};

int Race::getSpeed(){
    return this->speed;
};

 int * Race::getRace_Bonus() {
    return this->Race_Bonus;
}

 int * Race::getSubRace_Bonus() {
    return this->SubRace_Bonus;
}

int * Race::getSaveBool() {
    return this->SaveBool;
}

int * Race::getSkillBool(){
    return this->SkillBool;
}

int * Race::getSkillBonus() {
    return this->SkillBonus;
}

Race::~Race(){};


