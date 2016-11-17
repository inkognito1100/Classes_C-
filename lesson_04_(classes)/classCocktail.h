//
//  classCocktail.h
//  lesson_04_(classes)
//
//  Created by Tim on 22.10.16.
//  Copyright (c) 2016 Tim. All rights reserved.
//

#ifndef __lesson_04__classes___classCocktail__
#define __lesson_04__classes___classCocktail__

#include <iostream>
#include "classAlcohol.h"
#include "classComponentList.h"

using namespace std;

//описывает алкогольный коктейль
class Cocktail {
private:
    ComponentList components;  //указатель на список ингридиентов коктейля
    string name;    //название коктейля
    float cost;     //цена
public:
    Cocktail() {
        name = "unknown";
        cost = 0;
        components = *new ComponentList();
    }
    Cocktail(std::string s, float c){
        name = s;
        cost = c;
        components = *new ComponentList;
    }
    void SetCost(float c) {
        cost = c;
    }
    float GetCost() {
        return cost;
    }
    void SetName(string n) {
        name = n;
    }
    string GetName() {
        return name;
    }
    //добавление ингридиента в коктейль: указатель чистый алкогольный напиток и его количество
    void AddComponent(Alcohol *alc, int vol) {
        components.Add(1, alc, vol);
        return;
    }
    //подсчет крепость коктейля (считается объем чистого спирта и делится на полный объем коктейля)
    int GetCocktailDegree() {
        Component *now = NULL;
        int cocktailVolume = 0;
        int alcoholVolume = 0;
        for (int i=0; i < components.Length(); i++)
        {
            now = components.GetComponent(i);
            if (now) {
                cocktailVolume += now->volume;
                alcoholVolume += now->element->GetDegrees() * now->volume / 100;
            }
        }
        if (!cocktailVolume)
            return 0;
        else
            return 100 * alcoholVolume / cocktailVolume;
    }
    ~Cocktail(){
        components.~ComponentList();
    }
};

#endif /* defined(__lesson_04__classes___classCocktail__) */
