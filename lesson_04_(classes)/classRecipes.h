//
//  classRecipes.h
//  lesson_04_(classes)
//
//  Created by Tim on 05.12.16.
//  Copyright (c) 2016 Tim. All rights reserved.
//

#ifndef lesson_04__classes__classRecipes_h
#define lesson_04__classes__classRecipes_h
#include <iostream>

#define HASH 100
using namespace std;
typedef class Recipe* pRecipe;
//узел хеш-массива
struct Recipe {
    string name;            //название коктейля
    string description;     //рецепт изготовления
    struct Recipe *next;    //указатель на следующий узел с таким же хешем
};


class Recipes {
private:
    struct Recipe **hashTable;
    
    void FreeList(struct Recipe *now) {
        if (!now)
            return;
        FreeList(now->next);
        delete now;
        return;
    }
    //хеш-функция
    int HashFunction(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
            sum += (int)s[i];
        return sum % HASH;
    }
public:
    Recipes() {
        hashTable = new pRecipe[HASH];
        for (int i = 0; i < HASH; i++)
            hashTable[i]=NULL;
    }
    //добавление или замена рецепта
    void AddRecipe(string name, string description) {
        struct Recipe *buf = hashTable[HashFunction(name)];
        while ((buf) && (buf->next) && (buf->name != name))
            buf = buf->next;
        if (!buf) {
            buf = new Recipe();
            buf->name = name;
            buf->description = description;
            buf->next = NULL;
            hashTable[HashFunction(name)] = buf;
            return;
        }
        else {
            if (buf->name == name)
            {
                buf->description = description;
                return;
            }
            else
            {
                buf->next = new Recipe();
                buf = buf->next;
                buf->name = name;
                buf->description = description;
                buf->next = NULL;
                return;
            }
        }
    }
    //поиск рецепта
    void PrintRecipe(string name) {
        struct Recipe *buf = hashTable[HashFunction(name)];
        while ((buf) && (buf->name != name))
            buf = buf->next;
        if (buf)
            cout << "Для создания коктейля \"" << name << "\" нужно " << buf->description << endl;
        else
            cout << "Коктейль \"" << name << "\" не найден\n";
        return;
    }
    
    ~Recipes() {
        for (int i=0; i < HASH; i++)
            FreeList(hashTable[i]);
        delete [] hashTable;
    }
};

#undef HASH
#endif
