// main.cpp
#include "Mycode.hpp"
#include "Utilities.hpp"
#include <memory>
#include "GenericVehicle.hpp"

int main() {
    using namespace VehicleSystem;

    // Crearea unei instanțe de MotorcycleManager
    MotorcycleManager manager;

    // Adăugarea motocicletelor la manager folosind smart pointers
    manager.addMotorcycle(Utilities::makeUnique(new Motorcycle("Honda", "Shadow VT600", 2002, 3999.99)));
    manager.addMotorcycle(Utilities::makeUnique(new Motorcycle("Yamaha", "YZF1000RR", 2022, 15000.99)));
    manager.addMotorcycle(Utilities::makeUnique(new Motorcycle("Suzuki", "Intruder1000RR", 2005, 12900.99)));
    
    GenericVehicle<float> car("Volkswagen", "Passat", 2023, 45000.50);//clasa templetizata folosire
    Utilities::displayDetails(car);

        std::shared_ptr<Person> person = std::make_shared<Person>("John Doe");
        person->addMotorcycle(std::make_shared<Motorcycle>("Kawasaki", "Ninja ZX-10R", 2021, 15500.99));
        person->addMotorcycle(std::make_shared<Motorcycle>("Harley-Davidson", "Street Glide", 2019, 22000.50));

        // Afișarea detaliilor motocicletelor persoanei
        person->displayMotorcycles();
        
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