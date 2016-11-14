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
class Liquor {
protected:
    std::string name;    //название
    float cost;     //цена
public:
    Liquor() {
        name = "unknown";
        cost = 0;
    }
    Liquor(std::string n, float c) {
        name = n;
        cost = c;
    }
    void SetName(string n) {
        name = n;
    }
    void SetCost(float c) {
        cost = c;
    }
    string GetName() {
        return name;
    }
    float GetCost() {
        return cost;
    }
    virtual int GetDegrees() {
        return 0;
    }
    ~Liquor() {
        
    }
};

class Alcohol: public Liquor {
private:
    int degree;
public:
    Alcohol() {
        name = "unknown";
        degree = 0;
        cost = 0;
    }
    Alcohol(std::string n, float c, int deg) {
        name = n;
        degree = deg;
        cost = c;
    }
    void SetDegrees(int deg) {
        degree = deg;
    }
    int GetDegrees() {
        return degree;
    }
    ~Alcohol() {
        
    }
};

#endif /* defined(__lesson_04__classes___classAlcohol__) */
