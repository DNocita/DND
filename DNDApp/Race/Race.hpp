//
//  Race.hpp
//  DNDApp
//
//  Created by Diodato Nocita on 2019-04-04.
//  Copyright © 2019 Diodato Nocita. All rights reserved.
//

#ifndef Race_hpp
#define Race_hpp

#include <stdio.h>



class Race {
public:
    Race();
    ~Race();
    
    int getSpeed();
    int * getRace_Bonus();
    int * getSubRace_Bonus();
    int * getSaveBool();
    int * getSkillBool();
    int * getSkillBonus();
    
protected:
   int speed;
    int Race_Bonus[6]={};
    int SubRace_Bonus[6]={};
    int SaveBool[6]={};
    int SkillBool[18]={};
    int SkillBonus[18]={};
};

#endif /* Race_hpp */
