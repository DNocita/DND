//
//  main.cpp
//  DNDApp
//
//  Created by Diodato Nocita on 2019-04-04.
//  Copyright © 2019 Diodato Nocita. All rights reserved.
//

#include <iostream>


#include "main.hpp"

using namespace std;

//static int STATS = 6; // this is the number of stats for a DND Character, Will always be 6
//static int MAXLEVEL = 20; // this is the max level your stat can get from stat rolling without Rare items

int main(int argc, const char * argv[]) {
    Hill_Dwarf *n = new Hill_Dwarf;
    Character *c = new Character(n);


    for (int i=0;i<18 ; i++ ) {
        i<6? std::cout << c->getBonus()[i] : std::cout << "  ";
        std::cout << "     " << c->getSkillBonus()[i] << std::endl;
     //std::cout <<c->getStatTotals()[i] << "      "<<c->getBonus()[i]<< "      "<< n->getSaveBool()[i]<<"     "<< c->getSaveBonus()[i] << endl;
    }
    
    std::cout << c->getIniBonus() << std::endl;
    
    return 0; 
}
