#pragma once
#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};

template<typename T>
class LinkList
{
public:
    Node<T>* first;
    Node<T>** last;

    class ListIterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using difference_type = std::ptrdiff_t;

        ListIterator(Node<T>* node) : current(node) {}

        reference operator*() const { return current->data; }
        pointer operator->() const { return &current->data; }
        ListIterator& operator++() { current = current->next; return *this; }
        ListIterator operator++(int) { ListIterator tmp(current); ++(*this); return tmp; }
        bool operator==(const ListIterator& other) const { return current == other.current; }
        bool operator!=(const ListIterator& other) const { return !(*this == other); }

    private:
        Node<T>* current;
    };

    LinkList();
    LinkList(std::initializer_list<T> values);
    ~LinkList();
    void push_back(T value);
    void push_front(T value);
    void insert(size_t idx, T value);
    void pop_back();
    void pop_front();
    void remove_at(size_t index);
    int size() const;
    bool empty() const;
    void clear();
    T front() const;
    T back() const;
    T& operator[](const size_t index);
    const T& operator[](const size_t index) const;

    ListIterator begin();
    ListIterator end();
};

