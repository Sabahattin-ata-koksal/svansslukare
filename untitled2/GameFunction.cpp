//
// Created by user on 15.03.2024.
//
#include "GameFunction.h"
#include "event.h"

void ScoreCalculator(std::unique_ptr<MainShip>obj){
    float FinalScore{0};
    FinalScore = static_cast<float>(obj->getFuel()) * 5 + static_cast<float>(obj->getMoney()) * 10 + (obj->getHp()) * 10;
    std::cout<<"Oyun sonu skorunuz: "<<FinalScore;
}

void GameFunction(std::unique_ptr<MainShip>obj){
    int GameType{0};
    bool EAPsituation{false}; //korsanların çıkma durumu

    for(int turn = 0; turn < 5; ++turn) {
        if (obj->getFuel() <= 0 || obj->getHp() <= 0){
            std::cout<<"Yeterli yakitiniz veya saglik degeriniz yok. Yolculugun sonuna geldiniz....\n";
            break;
        }
        GameType = obj->firstRandom();
        std::cout<<turn+1<<".eventtesiniz\n";
        puts("");
        std::cout << "oyun turu" << GameType << "\n";
        puts("");
        if (GameType == 1) {
            EventAsteroidBelt(std::move(obj));
        } else if (GameType == 2) {
            EAPsituation = EventAbandonedPlanet(std::move(obj));
            if(EAPsituation == 1){
                PiratesChoices(std::move(obj));
            }
        } else if (GameType == 3) {
            PiratesChoices(std::move(obj));
        }
        puts("");
        std::cout<<"Event sonundaki degerleriniz--> hp:"<<obj->getHp()<<"  altin:"<<obj->getMoney()<<"  yakit:"<<obj->getFuel()<<"\n";
        puts("");
        //std::cin.ignore();
    }
    ScoreCalculator(std::move(obj));
}

