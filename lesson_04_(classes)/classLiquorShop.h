//
//  classLiquorShop.h
//  lesson_04_(classes)
//
//  Created by Tim on 22.10.16.
//  Copyright (c) 2016 Tim. All rights reserved.
//

#ifndef lesson_04__classes__classLiquorShop_h
#define lesson_04__classes__classLiquorShop_h

#include <iostream>
#include "classAlcohol.h"

using namespace std;

//алкогольный магазин
class LiquorShop {
protected:
    float income;   //выручка магазина
    std::string name;   //название магазина
public:
    LiquorShop() {
        income = 0;
        name = "unknown";
    }
    //у магазина может быть начальный капитал
    LiquorShop(std::string n, float sum) {
        name = n;
        income = sum;
    }
    void SetName(string n) {
        name = n;
    }
    string GetName() {
        return name;
    }
    float GetIncome() {
        return income;
    }
    //продать алкоголь
    virtual void Sell(Alcohol *element, int quantity) {
        income += (element->GetCost()) * quantity;
        std::cout << "В \"" << name << "\" продано " << quantity << " бутылок " << element->GetName() << std::endl;
    }
    //выводит выручку магазина
    void PrintIncome() {
        std::cout << "Сейчас в кассе \"" << name << "\" " << income << " рублей" << std::endl;
    }
    //в америке винные лавки часто грабят
    float Rob() {
        float output = income;
        if (output < 0)
            output = 0;
        else
            income = 0;
        return output;
    }
    ~LiquorShop() {
        
    }
};

#endif
