#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "EStackException.h"
#include "EStackEmpty.h"
template <class T>
class tmp_stack
{
private:
  int count;                     // Вершина стека - количество элементов типа T в стеке
  struct Node
  {
    const T stack;           //Значения 
    Node *next = nullptr;
    Node *prev = nullptr;
  };
  Node *tail;                   //Указатель на хвост
public:
    tmp_stack();
    ~tmp_stack();
    void push(const T value);    //Функция добавления элемента item типа T в стек
    const T pop();               //Функция извлечение объекта из стека;
    int Count();                 //Функция получения размерности стека;
};
template <class T>               //Конструктор
tmp_stack<T>::tmp_stack()
{
    tail = nullptr;
    count = 0;
}

template <class T>
tmp_stack<T>::~tmp_stack()       //Деструктор
{
    while (tail != nullptr)      //Удаление всех узлов пока хвост не пуст
    {
        Node* tmp = tail; 
        tail = tail->prev; 
        delete tmp; 
    }
    count = 0;
}
template <class T>
void tmp_stack<T>::push(const T value)   //Помещение объекта в стек;
{
    Node* tmp = new Node{ value, nullptr,tail};
    if (tmp == nullptr)
    {
        throw EStackException("Memory was not allocated");
    }
    tail = tmp;
    if (tail->prev) 
    {
        tail->prev->next = tmp;
    }
    count++;
}
template <class T>
 const T tmp_stack<T>::pop()           //Извлечение объекта из стека;
{
    if (tail== nullptr || count==0)    //Если стек пуст,возвращаем исключение
    {
        cout << "warning1";
        EStackEmpty();
        cout << "warning";
    }
    else
    {
       
        const T value = tail->stack; 
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) 
        {
            tail->next = nullptr;
        }
        delete tmp;               
        count--; 
       
        return value;                 
    }
}

template <class T>
int tmp_stack<T>::Count()              // Получение размерности стека.
{
    return count;
}

