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
#include "classCocktailHeap.h"

//бар, где продают как чистый алкоголь, так и коктейль
class CocktailBar: public LiquorShop {
private:
    CocktailHeap *queue;
    //продать напиток (не коктейль), метод приватный, т.к. нужно сделать заказ соответствующей функцией
    void Sell(Liquor *element, int quantity) {
        income += element->GetCost() * quantity;
        std::cout << "В \"" << name << "\" продано " << quantity << " порций " << element->GetName() << std::endl;
    }
    //продать коктейль, перегружает продажу алкоголя, по поводу привтности – аналогично
    void Sell(Cocktail *element, int quantity) {
        income += element->GetCost() * quantity;
        std::cout << "В \"" << name << "\" продано " << quantity << " коктейлей " << element->GetName() << std::endl;
    }
public:
    CocktailBar() {
        income = 0;
        name = "unknown";
        queue = new CocktailHeap();
    }
    CocktailBar(std::string n, float i) {
        name = n;
        income = i;
        queue = new CocktailHeap();
    }
    //заказ чистого алкоголя или безалкогольного напитка, наливается сразу
    void MakeOrder(Liquor* element, int quantity) {
        Sell(element, quantity);
    }
    //заказ коктейля, перегружает заказ чистого напитка, коктейль добавляется в кучу заказов с сортировкой по цене по возрастанию
    void MakeOrder(Cocktail* element, int quantity) {
        queue->Add(element, quantity);
    }
    //готовится count коктейлей из кучи, если в куче меньше коктейлей, чем count, то готовятся все, приготовленные коктейли удаляются из кучи заказов
    void MakeCocktail(int count) {
        while ((!queue->IsEmpty()) && (count > 0))
        {
            HeapNode *buf = queue->Get();
            Sell(buf->cocktail, buf->quantity);
            queue->Del();
            count--;
        }
    }
    //посетители могут сломать ч/л на определенную сумму
    void BreakSomething(float cost) {
        income -= cost;
        cout << "В баре \"" << name << "\" сломано предметов на сумму " << cost << " рублей\n";
    }
    ~CocktailBar() {
        queue->~CocktailHeap();
    }
};

#endif
