//
//  classComponentList.h
//  lesson_04_(classes)
//
//  Created by Tim on 24.10.16.
//  Copyright (c) 2016 Tim. All rights reserved.
//

#ifndef lesson_04__classes__classComponentList_h
#define lesson_04__classes__classComponentList_h

#include <iostream>

using namespace std;

//узел списка
struct Component {
    Alcohol *element;
    int volume;
    Component *next;
};

//список компонентов
class ComponentList {
private:
    Component *head;    //указатель на начало списка
public:
    ComponentList() {
        head = NULL;
    }
    //добавление узла по номеру, если узлов меньше, вернет false
    bool Add(int number, Alcohol *element, int vol) {
        int i = 0;
        Component *now = head, *buf;
        number--;
        while ((i<number) && (now))
        {
            i++;
            now = now->next;
        }
        if (i != number)
            return false;
        else
        {
            if (!head){
                head = new Component();
                head->next = NULL;
                head->element = element;
                head->volume = vol;
            }
            else
            {
                buf = now->next;
                now->next = new Component();
                now = now->next;
                now->next = buf;
                now->element = element;
                now->volume = vol;
            }
            return true;
        }
    }
    //удаление узла по номеру, если узлов меньше, вернет false
    bool Delete(int number) {
        int i = 1;
        Component *now = head, *buf;
        number--;
        if ((!head) || (number < 0))
            return false;
        if (0 == number)
        {
            buf = head;
            head = head->next;
            delete buf;
            return true;
        }
        now = now->next;
        while ((i < number) && (now->next))
        {
            i++;
            now = now->next;
        }
        if (i != number)
            return false;
        else
        {
            buf = now->next;
            if (buf->next)
                now->next = buf->next;
            else
                now->next = NULL;
            delete buf;
            return true;
        }
    }
    //проверка на пустоту
    bool IsEmpty() {
        return (!head);
    }
    //возвращает длину списка компонентов
    int Length() {
        int i = 0;
        Component *now = head;
        while (now)
        {
            i++;
            now = now->next;
        }
        return i;
    }
    //возвращает указатель на узел списка компонентов по номеру
    Component* GetComponent(int number) {
        Component *now = head;
        int i = 0;
        while ((i < number) && (now))
        {
            i++;
            now = now->next;
        }
        if (i != number)
            return NULL;
        else
            return now;
    }
    ~ComponentList() {
        while (!IsEmpty())
            Delete(1);
    }
};


#endif
