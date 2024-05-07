#include "LinkList.h"
#include <iostream>

template<typename T>
LinkList<T>::LinkList()
{
    first = nullptr;
    last = nullptr;
}

template<typename T>
LinkList<T>::LinkList(std::initializer_list<T> values)
{
    first = nullptr;
    last = nullptr;
    for (auto it = values.begin(); it != values.end(); ++it) {
        push_back(*it);
    }
}

template<typename T>
LinkList<T>::~LinkList()
{
    Node<T>* cur_node = first;
    while (cur_node != nullptr)
    {
        Node<T>* next_node = cur_node->next;
        delete cur_node;
        cur_node = next_node;
    }
}

template<typename T>
void LinkList<T>::push_back(T value)
{
    Node<T>* new_node = new Node<T>(value);
    if (first == nullptr)
    {
        first = new_node;
        last = &(new_node->next);
    }
    else
    {
        *last = new_node;
        last = &(new_node->next);
    }
}

template<typename T>
void LinkList<T>::push_front(T value)
{
    Node<T>* new_node = new Node<T>(value);
    new_node->next = first;
    first = new_node;
    if (new_node->next == nullptr)
    {
        last = &(new_node->next);
    }
}

template<typename T>
void LinkList<T>::insert(size_t idx, T value)
{
    if (idx < 0)
    {
        std::cerr << "Invalid index" << std::endl;
        return;
    }

    Node<T>* new_node = new Node<T>(value);
    if (idx == 0)
    {
        new_node->next = first;
        first = new_node;
        if (new_node->next == nullptr)
        {
            last = &(new_node->next);
        }
    }
    else
    {
        Node<T>* cur_node = first;
        int i = 0;
        while (cur_node != nullptr && i < idx - 1)
        {
            cur_node = cur_node->next;
            i++;
        }

        if (cur_node == nullptr)
        {
            std::cerr << "Invalid index" << std::endl;
            delete new_node;
            return;
        }

        new_node->next = cur_node->next;
        cur_node->next = new_node;
        if (new_node->next == nullptr)
        {
            last = &(new_node->next);
        }
    }
}

template<typename T>
void LinkList<T>::pop_back()
{
    if (first == nullptr)
    {
        return;
    }
    else if (first->next == nullptr)
    {
        delete first;
        first = nullptr;
        last = nullptr;
    }
    else
    {
        Node<T>* cur_node = first;
        while (cur_node->next->next != nullptr)
        {
            cur_node = cur_node->next;
        }
        delete cur_node->next;
        cur_node->next = nullptr;
        last = &(cur_node->next);
    }
}

template<typename T>
void LinkList<T>::pop_front()
{
    if (first == nullptr)
    {
        return;
    }
    Node<T>* temp = first;
    first = first->next;
    delete temp;
    if (first == nullptr)
    {
        last = &first;
    }
}

template<typename T>
void LinkList<T>::remove_at(size_t index)
{
    if (first == nullptr || index < 0)
    {
        return;
    }
    if (index == 0)
    {
        pop_front();
        return;
    }
    int count = 0;
    Node<T>* cur_node = first;
    Node<T>* prev_node = nullptr;
    while (cur_node != nullptr && count != index)
    {
        prev_node = cur_node;
        cur_node = cur_node->next;
        count++;
    }
    if (cur_node == nullptr)
    {
        return;
    }
    prev_node->next = cur_node->next;
    if (cur_node == *(last))
    {
        last = &(prev_node->next);
    }
    delete cur_node;
}

template<typename T>
T& LinkList<T>::operator[](const size_t index)
{
    Node<T>* cur_node = first;
    for (int i = 0; i < index; i++)
    {
        if (cur_node == nullptr)
        {
            throw std::out_of_range("Index out of range");
        }
        cur_node = cur_node->next;
    }
    if (cur_node == nullptr)
    {
        throw std::out_of_range("Index out of range");
    }
    return cur_node->data;
}

template<typename T>
T const& LinkList<T>::operator[](const size_t index) const
{
    Node<T>* cur_node = first;
    for (int i = 0; i < index; i++)
    {
        if (cur_node == nullptr)
        {
            throw std::out_of_range("Index out of range");
        }
        cur_node = cur_node->next;
    }
    if (cur_node == nullptr)
    {
        throw std::out_of_range("Index out of range");
    }
    return cur_node->data;
}

template<typename T>
int LinkList<T>::size() const
{
    int count = 0;
    Node<T>* cur_node = first;
    while (cur_node != nullptr)
    {
        count++;
        cur_node = cur_node->next;
    }
    return count;
}

template<typename T>
bool LinkList<T>::empty() const
{
    if (first == nullptr) return true;
    else return false;
}

template<typename T>
void LinkList<T>::clear()
{
    Node<T>* cur_node = first;
    while (cur_node != nullptr)
    {
        Node<T>* next_node = cur_node->next;
        delete cur_node;
        cur_node = next_node;
    }
    first = nullptr;
    last = nullptr;
}

template<typename T>
T LinkList<T>::back() const
{
    if (first != nullptr)
    {
        Node<T>* cur_node = first;
        while (cur_node->next != nullptr)
        {
            cur_node = cur_node->next;
        }
        return cur_node->data;
    }
}

template<typename T>
T LinkList<T>::front() const
{
    if (first != nullptr)
    {
        return first->data;
    }
}

template<typename T>
typename LinkList<T>::ListIterator LinkList<T>::begin()
{
 return ListIterator(first);
}

template<typename T>
typename LinkList<T>::ListIterator LinkList<T>::end()
{
 return ListIterator(nullptr);
}
