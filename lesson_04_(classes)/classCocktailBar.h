//
//  classCocktailBar.h
//  lesson_04_(classes)
//
//  Created by Tim on 22.10.16.
//  Copyright (c) 2016 Tim. All rights reserved.
//

#ifndef lesson_04__classes__classCocktailBar_h
#define lesson_04__classes__classCocktailBar_h

#include <iostream>
#include "classAlcohol.h"
#include "classCocktail.h"
#include "classLiquorShop.h"

//бар, где продают как чистый алкоголь, так и коктейль
class CocktailBar: public LiquorShop {
public:
    CocktailBar() {
        income = 0;
        name = "unknown";
    }
    CocktailBar(std::string n, float i) {
        name = n;
        income = i;
    }
    void Sell(Alcohol *element, int quantity) {
        income += element->GetCost() * quantity;
        std::cout << "В \"" << name << "\" продано " << quantity << " порций " << element->GetName() << std::endl;
    }
    //продать коктейль, перегружает продажу алкоголя
    void Sell(Cocktail *element, int quantity) {
        income += element->GetCost() * quantity;
        std::cout << "В \"" << name << "\" продано " << quantity << " коктейлей " << element->GetName() << std::endl;
    }
    //посетители могут сломать ч/л на определенную сумму
    void BreakSomething(float cost) {
        income -= cost;
    }
    ~CocktailBar() {
        
    }
};

#endif
