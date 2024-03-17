
#ifndef SVANSSLUKARE_FINAL_NORMALSHIP_H
#define SVANSSLUKARE_FINAL_NORMALSHIP_H

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
        fuel = fuel-FuelDecremention;
    }
    void decrementHp(float DHvalue) override{
        hp = hp - (DHvalue * damageX);
    }
    void decrementHpAsteroid() override{
        hp = hp - 10;
    }
};


#endif //SVANSSLUKARE_FINAL_NORMALSHIP_H


#endif //UNTITLED2_NORMALSHIP_H
