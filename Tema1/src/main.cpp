#include <iostream>  
#include "Mycode.hpp"

int main() {
    MotorcycleManager manager;

    manager.addMotorcycle("Honda", "Shadow VT600", 2002, 3999.99);
    manager.addMotorcycle("Yamaha", "YZF1000RR", 2022, 15000.99);
    manager.addMotorcycle("Suzuki", "Intruder1000RR", 2005, 12900.99);

    std::cout << "Lista inițială de motociclete:\n";
    manager.listMotorcycles();

    manager.removeMotorcycle("Yamaha", "YZF1000RR");

    std::cout << "\nLista de motociclete după ștergerea unei motociclete:\n";
    manager.listMotorcycles();

    return 0;
}