#include <iostream>
#include "date.h"

int main() {
    Date d1(25, 12, 2023);

    std::cout << "Initial date: " << d1 << std::endl;

    ++d1;
    std::cout << "Date after increment: " << d1 << std::endl;

    Date d2(25, 12, 2023);
    if (d1 == d2) {
        std::cout << "d1 and d2 are equal" << std::endl;
    }
    else {
        std::cout << "d1 and d2 are not equal" << std::endl;
    }

    std::cout << "Enter day, month, and year: ";
    std::cin >> d2;
    std::cout << "You entered: " << d2 << std::endl;

    return 0;
}