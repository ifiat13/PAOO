#include <iostream>  
#include "Mycode.hpp"

int main() {
    MotorcycleManager manager;

    manager.addMotorcycle("Honda", "CBR600RR", 2022, 12999.99);
    manager.addMotorcycle("Kawasaki", "Ninja ZX-6R", 2022, 11999.99);

    std::cout << "Lista inițială de motociclete:\n";
    manager.listMotorcycles();

    manager.removeMotorcycle("Honda", "CBR600RR");

    std::cout << "\nLista de motociclete după ștergerea unei motociclete:\n";
    manager.listMotorcycles();

    return 0;
}