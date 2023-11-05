#include "Mycode.hpp"
#include <iostream>

int main() {
    MotorcycleManager manager;

    manager.addMotorcycle(Motorcycle("Honda", "Shadow VT600", 2002, 3999.99, true));
    manager.addMotorcycle(Motorcycle("Yamaha", "YZF1000RR", 2022, 15000.99, false));
    manager.addMotorcycle(Motorcycle("Suzuki", "Intruder1000RR", 2005, 12900.99, true));

    std::cout << "Lista inițială de motociclete:\n";
    manager.listMotorcycles();

    manager.removeMotorcycle("Yamaha", "YZF1000RR");

    std::cout << "\nLista de motociclete după ștergerea unei motociclete:\n";
    manager.listMotorcycles();

    manager.updatePrices(10); // Crește prețurile cu 10%

    std::cout << "\nLista de motociclete după actualizarea prețurilor:\n";
    manager.listMotorcycles();

    return 0;
}
