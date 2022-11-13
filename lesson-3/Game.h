#include <iostream>
#include "Title.h"

#ifndef CPP_GAME_H
#define CPP_GAME_H

using namespace std;

class Game: Title{
private:
    Title title;
    string devStudioName;
    double price;
    int yearOfRelease;
public:

    Game (Title title, string devStudioName, double price, int yearOfRelease){
        this->title = title;
        this->devStudioName = devStudioName;
        this->price = price;
        this->yearOfRelease = yearOfRelease;
    }

    void ShowGameInfo()  {
        cout << "Title: " << title.value("short") << '\n';
        cout << "Created by: " << devStudioName << '\n';
        cout << "Release year: " << yearOfRelease << '\n';
        cout << "Current price: " << price << '\n';
    }

    void ChangeGamePrice(double price) {
        this->price = price;
    }

};
#endif //CPP_GAME_H