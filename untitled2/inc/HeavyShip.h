
#ifndef SVANSSLUKARE_FINAL_HEAVYSHIP_H
#define SVANSSLUKARE_FINAL_HEAVYSHIP_H

#include "ship.h"

class HeavyShip : public MainShip{
public:
    HeavyShip() : MainShip(){
        escapeX = escapeX * HSexapeX;
        damageX = damageX * HSdamageX;
        std::cout << "constructor of HeavyShip: " << "\n";
    }

public:
    void incrementMoney() override{
        money = money+10;
    }
    void decrementMoney(int DMvalue) override{
        money = money - DMvalue;
    }
    void decrementFuel() override{
        fuel = fuel - FuelDecremention;
    }
    void decrementHp(float DHvalue) override{
        hp = hp - (DHvalue * damageX);
    }
    void decrementHpAsteroid() override{
        hp = hp - 10;
    }
};

#endif //SVANSSLUKARE_FINAL_HEAVYSHIP_H
