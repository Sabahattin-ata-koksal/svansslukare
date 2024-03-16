//
// Created by user on 15.03.2024.
//

#ifndef UNTITLED2_SHIP_H
#define UNTITLED2_SHIP_H
#include "randomizer.h"
static constexpr float RSexapeX{1.5};
static constexpr float HSexapeX{0.5};
static constexpr float RSdamageX{1.5};
static constexpr float HSdamageX{0.5};
static constexpr int FuelDecrementor{33};

class MainShip : public Randomizer{
protected:
    int fuel;
    float hp;
    int money;
    float damageX;
    float escapeX;
public:
    MainShip(){
        fuel = 99;
        hp = 100.0f;
        money = 0;
        damageX =1;
        escapeX =1;
        std::cout << "constructor of MainShip" << "\n";
    }
    inline int getFuel(){
        return fuel;
    }
    inline float getHp(){
        return hp;
    }
    inline int getMoney(){
        return money;
    }
    inline int getDamageX(){
        return damageX;
    }
    inline int getEscapeX(){
        return escapeX;
    }

    inline virtual void incrementMoney(){}
    inline virtual void decrementMoney(int DMvalue){}
    inline virtual void decrementFuel(){}
    inline virtual void decrementHp(float DHvalue){}
    inline virtual void decrementHpAsteroid(){}

};





#endif //UNTITLED2_SHIP_H
