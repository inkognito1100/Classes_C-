//
//  classAlcohol.h
//  lesson_04_(classes)
//
//  Created by Tim on 22.10.16.
//  Copyright (c) 2016 Tim. All rights reserved.
//

#ifndef __lesson_04__classes___classAlcohol__
#define __lesson_04__classes___classAlcohol__

#include <iostream>
using namespace std;

//класс описывает чистый алкогольный напиток (напиток может быть и не алкогольным, вводить новый класс смысла нет, т.к. у него поля будут идентичны классу алкоголя)
class Alcohol {
private:
    std::string name;    //название
    int degrees;    //крепость
    float cost;     //цена
public:
    Alcohol *lowerDeg, *higherDeg;   //указатели на более слабый и более крепкий напитки
    Alcohol() {
        name = "unknown";
        degrees = 0;
        cost = 0;
        lowerDeg = NULL;
        higherDeg = NULL;
    }
    Alcohol(std::string n, int deg, float c, Alcohol *low, Alcohol *high) {
        name = n;
        degrees = deg;
        cost = c;
        lowerDeg = low;
        higherDeg = high;
    }
    void SetName(string n) {
        name = n;
    }
    void SetCost(float c) {
        cost = c;
    }
    void SetDegrees(int deg) {
        degrees = deg;
    }
    string GetName() {
        return name;
    }
    float GetCost() {
        return cost;
    }
    int GetDegrees() {
        return degrees;
    }
    ~Alcohol() {
        delete lowerDeg;
        delete higherDeg;
    }
};

#endif /* defined(__lesson_04__classes___classAlcohol__) */
