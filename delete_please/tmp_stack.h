#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "EStackException.h"
#include "EStackEmpty.h"
template <class T>
class tmp_stack
{
private:
  int count;                     // ������� ����� - ���������� ��������� ���� T � �����
  struct Node
  {
    const T stack;           //�������� 
    Node *next = nullptr;
    Node *prev = nullptr;
  };
  Node *tail;                   //��������� �� �����
public:
    tmp_stack();
    ~tmp_stack();
    void push(const T value);    //������� ���������� �������� item ���� T � ����
    const T pop();               //������� ���������� ������� �� �����;
    int Count();                 //������� ��������� ����������� �����;
};
template <class T>               //�����������
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
    count = 0;
}
template <class T>
void tmp_stack<T>::push(const T value)   //��������� ������� � ����;
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
 const T tmp_stack<T>::pop()           //���������� ������� �� �����;
{
    if (tail== nullptr || count==0)    //���� ���� ����,���������� ����������
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
int tmp_stack<T>::Count()              // ��������� ����������� �����.
{
    return count;
}

