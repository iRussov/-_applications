#include <iostream>
#include "LinkList.h"
#include "LinkList.cpp"
#include <numeric>

void print_lst(const LinkList<char>& l) {
    for (int i = 0; i < l.size()-1; i++) {
        std::cout << l[i] << " -> ";
    }
    std::cout << l[l.size()-1] << std::endl;
}

int main()
{
    LinkList <char> lst;
    std::cout << std::boolalpha << lst.empty() << std::endl;
    
    for (int i = 0; i < 5; i++)
    lst.push_back(char('a' + i));
    
    print_lst(lst);
    
    for (int i = 0; i < 5; i++)
    lst.insert(0, char('z' - i));
    
    print_lst(lst);
    
    for (size_t i = 0; i != lst.size(); i++)
    lst[i] = char('a' + i);
    print_lst(lst);
    
    lst.pop_back();
    lst.pop_front();
 
    print_lst(lst);
    
    lst.remove_at(5);
    lst.insert(3, 'o');
    
    print_lst(lst);
    
    lst.clear();
    
    lst.push_back('q');
    lst.push_back('w');
    
    std::cout << lst.size() << ' ' << std::boolalpha << lst.empty() << std::endl;

    LinkList <int> l = { 3 , 5 , 2 , 7 };// проверка итератора
    for (auto& i : l) i += 2;
    auto lambda = [&l](int a, int b) { return a + b * 10; };
    std::cout << std::accumulate(l.begin(), l.end(), 0, lambda) << "\n";// 250
}

