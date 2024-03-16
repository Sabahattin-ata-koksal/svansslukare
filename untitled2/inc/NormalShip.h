//
// Created by user on 16.03.2024.
//

#ifndef UNTITLED2_NORMALSHIP_H
#define UNTITLED2_NORMALSHIP_H
#include "ship.h"

class NormalShip : public MainShip{
public:
    NormalShip() : MainShip(){
        std::cout << "constructor of NormalShip" << "\n";
    }

public:
    void incrementMoney() override{
        money = money+10;
    }
    void decrementMoney(int DMvalue) override{
        money = money - DMvalue;
    }
    void decrementFuel() override{
        fuel = fuel-FuelDecrementor;
    }
    void decrementHp(float DHvalue) override{
        hp = hp - (DHvalue * damageX);
    }
    void decrementHpAsteroid() override{
        hp = hp - 10;
    }
};


#endif //UNTITLED2_NORMALSHIP_H
