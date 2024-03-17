#ifndef SVANSSLUKARE_FINAL_RANDOMIZER_H
#define SVANSSLUKARE_FINAL_RANDOMIZER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <ctime>

class Randomizer {
public:

    [[nodiscard]] int firstRandom(){  // firstRandom hangi event'in geleceğini belirliyor. 1 AsteroidBelt'e, 2 AbandonedPlanet'e ve 3 PiratesEscape'e gidiyor.
        int FirstRandomResult{0};
        FirstRandomResult = 1 + rand() % 3;
        return FirstRandomResult;
    }

    [[nodiscard]] int AsteroidBelt(float x)const{
        int AsteroidResult;
        AsteroidResult = 0; // burada her if'de eğer 0 gelirse gemi hasar almayacak, 1 gelirse 10 hasar alacak
        if ( x == 0.5f){
            AsteroidResult = 1 + rand()%4;
            if (AsteroidResult == 1){
                return 0;
            }
            else {
                return 1;
            }
        }
        else if (x == 1.0f) {
            AsteroidResult = 1 + rand()%4;
            if (AsteroidResult == 2 || AsteroidResult == 1) {
                return 0;
            }
            else {
                return 1;
            }
        }
        else if(x == 1.5f) {
            AsteroidResult = 1 + rand() % 4;
            if (AsteroidResult == 1 || AsteroidResult == 2 || AsteroidResult == 3) {
                return 0;
            }
            else {
                return 1;
            }
        }
        return 13;
    }

    [[nodiscard]] int AbandonedPlanet(){
        int AbandonedResult{0};
        AbandonedResult = rand()%2; // 0 gelirse para, 1 gelirse korsanlar gelecek
        return AbandonedResult;
    }

    [[nodiscard]] int PiratesEscape(float x)const {
        int PiratesEscapeResult{0}; // 0 gelirse gemi kaçacak 1 gelirse gemi kaçamayacak
        if (x == 0.5f) {
            PiratesEscapeResult = 1 + rand() % 4;
            if (PiratesEscapeResult == 1) {
                return 0;
            }
            else {
                return 1;
            }
        }
        else if (x == 1.0f) {
            PiratesEscapeResult = 1 + rand() % 4;
            if (PiratesEscapeResult == 1 || PiratesEscapeResult == 2) {
                return 0;
            }
            else {
                return 1;
            }
        }
        else if (x == 1.5f) {
            PiratesEscapeResult = 1 + rand() % 4;
            if (PiratesEscapeResult == 1 || PiratesEscapeResult == 2 || PiratesEscapeResult == 3) {
                return 0;
            }
            else {
                return 1;
            }
        }
        return 13;
    }

    [[nodiscard]] int PiratesFight(){
        int PiratesFightResult{0};
        PiratesFightResult = rand()%2;// 0 gelirse kazancak, 1 gelirse kaybedip 30 hasar alacak
        if (PiratesFightResult == 0){
            return 0;
        }
        else if(PiratesFightResult == 1){
            return 1;
        }
        return 13;
    }

    [[nodiscard]] int PiratesBargain(){
        int PiratesBargainResult{0};
        PiratesBargainResult = 1 + rand()%3; // 1 gelirse 10, 2 gelirse 20, 3 gelirse 30 isteyecekler

        switch(PiratesBargainResult){
            case 1:
                return 10;
            case 2:
                return 20;
            case 3:
                return 30;
        }
        return 13;
    }

};

#endif //SVANSSLUKARE_FINAL_RANDOMIZER_H
