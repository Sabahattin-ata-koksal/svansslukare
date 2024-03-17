#include "functions.h"
#include "ship.h"
#include "GameFunction.h"


void print() {
    puts("oyunumuza hosgeldiniz");
    puts("3 tip gemimiz bulunmaktadir hizli gemi, guclu gemi ve normal gemi hangisini secmek istersiniz");
    puts("hizli, guclu veya normal yaziniz");
}



 void LowerCase(std::string &ToLower){

    std::transform(ToLower.begin(), ToLower.end(), ToLower.begin(), ::tolower);
}


void ShipChoosing(const std::vector<std::string>& ShipTypes, std::string ChosenType){

    LowerCase(ChosenType);


    for(const std::string &ShipType : ShipTypes){
        if(ChosenType == ShipType){
            puts("Gecerli bir gemi turu girdiniz");
            std::cout << "sectiginiz gemi tipi:" << ShipType << "\n";
            break;
        }
        else if(ShipType == ShipTypes.back()){
            puts("Gecerli bir gemi turu girmediniz...");
        }
    }


}

void SetPointer(RapidShip &RShip, HeavyShip &HShip, NormalShip &NShip, MainShip* GameObject, const std::vector<std::string>& ShipTypes, const std::string& ChosenType){

    if(ChosenType == ShipTypes.at(0)){
        GameObject = &RShip;
        puts("hizli gemi olusturuldu");
        puts(" \n \n ");
        std::cin.ignore();
        GameFunction(GameObject);

    }
    else if(ChosenType == ShipTypes.at(1)){
        GameObject = &HShip;
        puts("guclu gemi olusturuldu");
        puts(" \n \n ");
        std::cin.ignore();
        GameFunction(GameObject);

    }
    else if(ChosenType == ShipTypes.at(2)){
        GameObject = &NShip;
        puts("Normal gemi olusturuldu");
        puts(" \n \n ");
        std::cin.ignore();
        GameFunction(GameObject);

    }

}
