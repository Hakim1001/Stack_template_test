#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "EStackException.h"
#include "EStackEmpty.h"
#include <functional>
template <class T>
class tmp_stack
{
private:
  int count=0;                     // ������� ����� - ���������� ��������� ���� T � �����
  struct Node
  {
    const T stack;                 //�������� 
    Node *prev = nullptr;
  };
  Node *tail=nullptr;                   //��������� �� �����
public:
    void ForEach(std::function<void(const T & value)> f) const;    //������� ������ ���� ���������� ��������
    void Clear();
    tmp_stack();
    ~tmp_stack();
    void push(const T &value);      //������� ���������� �������� item ���� T � ����
    const T pop();                  //������� ���������� ������� �� �����;
    int Count();                    //������� ��������� ����������� �����;
};
template <class T>                  //�����������
tmp_stack<T>::tmp_stack()
{
    tail = nullptr;
    count = 0;
}

template <class T>
tmp_stack<T>::~tmp_stack()       //����������
{
    while (tail != nullptr)      //�������� ���� ����� ���� ����� �� ����
    {
        Node* tmp = tail; 
        tail = tail->prev; 
        delete tmp; 
    }
    
}
template <class T>
void tmp_stack<T>::push(const T &value)                   //��������� ������� � ����;
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
 const T tmp_stack<T>::pop()                   //���������� ������� �� �����;
{
  
         if (tail == nullptr || count == 0)    //���� ���� ����,���������� ����������
         {
             throw EStackEmpty();
         }
         else
         {

             const T value = tail->stack;           // ��������� �������� �����
             Node* tmp = tail;                      // ��������� ������ �� �����
             tail = tail->prev;                     // ���������� ����� ����� �� ������������� �����
             delete tmp;
             count--;

             return value;
         }
}

// ������� �������� ���� ��������� �����, ������������ ��� ������ � ����.
// �������� ���������� �� ������, �. �. � ������� �� Pop, ��� �� ���������
 template <class T>
 void tmp_stack<T>::ForEach(std::function<void(const T & value)> f) const
 {
     Node* it = tail; // ������� ���� ���������, ������� � ����������

     while (it != nullptr) // ���������� ������
     {
         f(it->stack); // ����� ������� �������� �����

         it = it->prev;
     }
 }

template <class T>
int tmp_stack<T>::Count()              // ��������� ����������� �����.
{
    return count;
}

template <class T>
void tmp_stack<T>::Clear()
{
    while (tail != nullptr) // ���� � ����� ���� ��������
    {
        Node* tmp = tail; // ��������� ��������� �������

       tail = tail->prev; // ������ ��������� ��������� �������������

        delete tmp; // ������� ����������� ��������� �������
    }
}