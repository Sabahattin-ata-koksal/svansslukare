
#ifndef SVANSSLUKARE_FINAL_SHIP_H
#define SVANSSLUKARE_FINAL_SHIP_H

#include "randomizer.h"
static constexpr float RSexapeX{1.5};
static constexpr float HSexapeX{0.5};
static constexpr float RSdamageX{1.5};
static constexpr float HSdamageX{0.5};
constexpr int FuelDecremention{33};

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

public:

    [[nodiscard]] inline int getFuel() const{
        return fuel;
    }
    [[nodiscard]] inline float getHp() const{
        return hp;
    }
    [[nodiscard]] inline int getMoney() const{
        return money;
    }
    [[nodiscard]] inline float getDamageX() const{
        return damageX;
    }
    [[nodiscard]] inline float getEscapeX() const{
        return escapeX;
    }

    inline virtual void incrementMoney(){}
    inline virtual void decrementMoney(int DMvalue){}
    inline virtual void decrementFuel(){}
    inline virtual void decrementHp(float DHvalue){}
    inline virtual void decrementHpAsteroid(){}

};

#endif //SVANSSLUKARE_FINAL_SHIP_H




#endif //UNTITLED2_SHIP_H
