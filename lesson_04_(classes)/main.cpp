//
//  main.cpp
//  lesson_04_(classes)
//
//  Created by Tim on 22.10.16.
//  Copyright (c) 2016 Tim. All rights reserved.
//

#include <iostream>
#include "classAlcohol.h"
#include "classCocktail.h"
#include "classLiquorShop.h"
#include "classCocktailBar.h"
#include "classRecipes.h"

using namespace std;

int main()
{
    Liquor *juice = new Alcohol("Orange juice", 0, 100);
    Alcohol *vodka = new Alcohol("Vodka", 40, 500);
    Cocktail *screwdriver = new Cocktail("Screwdriver", 300);
    Recipes *recipiesBook = new Recipes();
    screwdriver->AddComponent(vodka, 50);
    screwdriver->AddComponent(juice, 150);
    cout << "Крепость отвертки: " << screwdriver->GetCocktailDegree() << "%\n";
    LiquorShop shop = *new LiquorShop("Beer 24", 0);
    shop.PrintIncome();
    shop.Sell(vodka,5);
    shop.PrintIncome();
    cout << "Из магазина украли: " << shop.Rob() << endl;
    shop.PrintIncome();
    CocktailBar bar = *new CocktailBar("Боржч", 0);
    bar.PrintIncome();
    bar.MakeOrder(vodka, 5);
    bar.MakeOrder(screwdriver, 5);
    bar.MakeCocktail(2);
    bar.PrintIncome();
    bar.BreakSomething(300);
    bar.PrintIncome();
    
    recipiesBook->AddRecipe("screwdriver", "blablabla");
    recipiesBook->PrintRecipe("screwdriver");
    recipiesBook->PrintRecipe("12123123");
    
    delete juice;
    delete vodka;
    delete screwdriver;
    shop.~LiquorShop();
    bar.~CocktailBar();
    delete recipiesBook;
    return 0;
}
