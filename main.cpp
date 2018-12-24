#include <iostream>
#include "Odgovor.h"
#include "Pitanje.h"
#include "Test.h"

int main() {
    std::cout << "Hello, World!" << std::endl;


    Test t1;
    int criteria=5;

    t1.ispisiPitanja([&criteria](int n)->bool{ return n>criteria;});
    return 0;
}