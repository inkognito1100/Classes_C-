//
//  classCocktailHeap.h
//  lesson_04_(classes)
//
//  Created by Tim on 17.11.16.
//  Copyright (c) 2016 Tim. All rights reserved.
//

#ifndef lesson_04__classes__classCocktailHeap_h
#define lesson_04__classes__classCocktailHeap_h

#include <iostream>
#include <cstring>
#include "classCocktail.h"

//структура описывает один элемент кучи заказов
struct HeapNode {
    Cocktail *cocktail;     //указатель на коктейль
    int quantity;       //количество заказанных коктейлей
};

class CocktailHeap {
private:
    HeapNode *heap;     //указатель на кучу
    int length;     //размер кучи, динамически увеличивается
    int amount;     //количество заказов в куче
public:
    CocktailHeap() {
        heap = NULL;
        length = 0;
        amount = 0;
    }
    //добавление заказа в кучу
    void Add(Cocktail* coc, int quant) {
        int now;
        if (amount >= length)
        {
            length = (length + 1) * 2 - 1;
            HeapNode *buf = new HeapNode[length];
            memcpy(buf, heap, amount * sizeof(HeapNode*));
            delete [] heap;
            heap = buf;
        }
        heap[amount].cocktail = coc;
        heap[amount].quantity = quant;
        now = amount++;
        while ((now > 0) && (heap[now].cocktail->GetCost() > heap[(now - 1) / 2].cocktail->GetCost()))
        {
            HeapNode buf = heap[now];
            heap[now] = heap[(now - 1) / 2];
            heap[(now - 1) / 2] = buf;
            now = (now - 1) / 2;
        }
        return;
    }
    //проверка кучи на пустоту
    bool IsEmpty() {
        return (0 == amount);
    }
    //получение указателя на самый дорогой заказ в куче
    HeapNode* Get() {
        if (!IsEmpty())
            return &heap[0];
        else
            return NULL;
    }
    //удаление самого дорогого заказа из кучи
    void Del() {
        int now, next;
        if (IsEmpty())
            return;
        amount--;
        heap[0] = heap[amount];
        now = 0;
        next = now * 2 + 1;
        while ((next + 1 < amount))
        {
            if ((heap[now].cocktail->GetCost() < heap[next].cocktail->GetCost()) || (heap[now].cocktail->GetCost() < heap[next + 1].cocktail->GetCost()))
            {
                if (heap[next].cocktail->GetCost() < heap[next + 1].cocktail->GetCost())
                    next = next + 1;
                HeapNode buf = heap[now];
                heap[now] = heap[next];
                heap[next] = buf;
                now = next;
                next = now * 2 + 1;
            }
            else
                break;
        }
        if ((next < amount) && (heap[now].cocktail->GetCost() < heap[next].cocktail->GetCost()))
        {
            HeapNode buf = heap[now];
            heap[now] = heap[next];
            heap[next] = buf;
            now = next;
        }
        return;
    }
    ~CocktailHeap() {
        
    }
};

#endif
