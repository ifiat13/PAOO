#include "Mycode.hpp"
#include <memory>

int main() {
    using namespace VehicleSystem;

    // Crearea unei instanțe de MotorcycleManager
    MotorcycleManager manager;

    // Adăugarea motocicletelor la manager folosind smart pointers
    manager.addMotorcycle(std::make_unique<Motorcycle>("Honda", "Shadow VT600", 2002, 3999.99));
    manager.addMotorcycle(std::make_unique<Motorcycle>("Yamaha", "YZF1000RR", 2022, 15000.99));
    manager.addMotorcycle(std::make_unique<Motorcycle>("Suzuki", "Intruder1000RR", 2005, 12900.99));

    // Afișarea listei inițiale de motociclete
    std::cout << "Lista inițială de motociclete:\n";
    manager.listMotorcycles();

    // Ștergerea unei motociclete din manager
    manager.removeMotorcycle("Yamaha", "YZF1000RR");

    // Afișarea listei de motociclete după ștergerea unei motociclete
    std::cout << "\nLista de motociclete după ștergerea unei motociclete:\n";
    manager.listMotorcycles();

    // Actualizarea prețurilor cu un procentaj dat
    manager.updatePrices(10); // Crește prețurile cu 10%

    // Afișarea listei de motociclete după actualizarea prețurilor
    std::cout << "\nLista de motociclete după actualizarea prețurilor:\n";
    manager.listMotorcycles();

    return 0;
}
