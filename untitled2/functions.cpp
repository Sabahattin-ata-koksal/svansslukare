//
// Created by user on 16.03.2024.
//
#include "functions.h"
#include "GameFunction.h"

inline void LowerCase(std::string &ToLower){

    std::transform(ToLower.begin(), ToLower.end(), ToLower.begin(), ::tolower);
}


void ShipChoosing(const std::vector<std::string>& ShipTypes, std::string ChosenType){

    LowerCase(ChosenType);


    for(const std::string &ShipType : ShipTypes){
        if(ChosenType == ShipType){
            puts("gecerli bir tur girdiniz");
            break;
        }
        else if(ShipType == ShipTypes.back()){
            puts("gecerli bir sonuc girmedin bitch");
        }
    }


}

void SetPointer(RapidShip &RShip, HeavyShip &HShip, NormalShip &NShip, std::unique_ptr<MainShip>GameObject,const std::vector<std::string>& ShipTypes, const std::string& ChosenType){

    if(ChosenType == ShipTypes.at(0)){
        GameObject = static_cast<std::unique_ptr<MainShip>>(&RShip);
        puts("hizli gemi olusturuldu");
        GameFunction(std::move(GameObject));


    }
    else if(ChosenType == ShipTypes.at(1)){
        GameObject = static_cast<std::unique_ptr<MainShip>>(&HShip);
        puts("guclu gemi olusturuldu");
        GameFunction(std::move(GameObject));

    }
    else if(ChosenType == ShipTypes.at(2)){
        GameObject = static_cast<std::unique_ptr<MainShip>>(&NShip);
        puts("Normal gemi olusturuldu");
        GameFunction(std::move(GameObject));

    }

}

