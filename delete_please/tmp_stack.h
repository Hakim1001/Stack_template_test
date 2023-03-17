#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "EStackException.h"
#include "EStackEmpty.h"
#include <functional>
template <class T>
class tmp_stack
{
private:
  int count=0;                     // Вершина стека - количество элементов типа T в стеке
  struct Node
  {
    const T stack;                 //Значения 
    Node *prev = nullptr;
  };
  Node *tail=nullptr;                   //Указатель на хвост
public:
    void ForEach(std::function<void(const T & value)> f) const;    //Функция обхода всех хранящихся значений
    void Clear();
    tmp_stack();
    ~tmp_stack();
    void push(const T &value);      //Функция добавления элемента item типа T в стек
    const T pop();                  //Функция извлечение объекта из стека;
    int Count();                    //Функция получения размерности стека;
};
template <class T>                  //Конструктор
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
    
}
template <class T>
void tmp_stack<T>::push(const T &value)                   //Помещение объекта в стек;
{
    Node* tmp = new Node{ value,tail};
    if (tmp == nullptr)
    {
        throw EStackException("Memory was not allocated");
    }
    tail = tmp;

    count++;
}
template <class T>
 const T tmp_stack<T>::pop()                   //Извлечение объекта из стека;
{
  
         if (tail == nullptr || count == 0)    //Если стек пуст,возвращаем исключение
         {
             throw EStackEmpty();
         }
         else
         {

             const T value = tail->stack;           // сохраняем значение звена
             Node* tmp = tail;                      // сохраняем ссылку на звено
             tail = tail->prev;                     // перемещаем конец стэка на предпоследнее звено
             delete tmp;
             count--;

             return value;
         }
}

// функция перебора всех элементов стека, используется для вывода в файл.
// значения передаются по ссылке, т. к. в отличии от Pop, они не удаляются
 template <class T>
 void tmp_stack<T>::ForEach(std::function<void(const T & value)> f) const
 {
     Node* it = tail; // перебор всех элементов, начиная с последнего

     while (it != nullptr) // заканчивая первым
     {
         f(it->stack); // вызов функции обратной связи

         it = it->prev;
     }
 }

template <class T>
int tmp_stack<T>::Count()              // Получение размерности стека.
{
    return count;
}

template <class T>
void tmp_stack<T>::Clear()
{
    while (tail != nullptr) // пока в стеке есть элементы
    {
        Node* tmp = tail; // сохраняем последний элемент

       tail = tail->prev; // делаем последним элементом предпоследний

        delete tmp; // удаляем сохраненный последний элемент
    }
}