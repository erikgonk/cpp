#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed b( a );
    Fixed c;
    
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    a.setRawBits(10);
    std::cout << a.getRawBits() << std::endl;

    b.setRawBits(20);
    std::cout << b.getRawBits() << std::endl;

    c.setRawBits(30);
    std::cout << c.getRawBits() << std::endl;
    
    return 0;
}
