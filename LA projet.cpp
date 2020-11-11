#define _CRTDBG_MAP_ALLOC
#include <stdio.h> 
#include <crtdbg.h>
#include <iostream>
#include "Header.hpp"

int main()
{
    Sommet a("A", 3);
    Sommet b("B", 1);
    Sommet c = a + b;
    ArbreB tree1(c);
    Sommet d("C", 2);
    ArbreB tree2(d);
    ArbreB tree = tree1 + tree2;
    tree.print();
    std::cout << tree.search("A") << std::endl;
    return 0;
}