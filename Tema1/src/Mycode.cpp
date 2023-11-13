// Mycode.cpp
#include "Mycode.hpp"

namespace VehicleSystem {

    // Implementarea clasei Motorcycle
    Motorcycle::Motorcycle(const std::string& brand, const std::string& model, int year, float price)
        : brand(brand), model(model), year(year), price(price) {}

    Motorcycle::~Motorcycle() {
        std::cout << "Motocicleta " << brand << " " << model << " a fost distrusă." << std::endl;
    }

    Motorcycle::Motorcycle(const Motorcycle& other)
        : brand(other.brand), model(other.model), year(other.year), price(other.price) {}

    Motorcycle& Motorcycle::operator=(const Motorcycle& other) {
        if (this == &other) {
            return *this;
        }

        brand = other.brand;
        model = other.model;
        year = other.year;
        price = other.price;
        return *this;
    }

    Motorcycle::Motorcycle(Motorcycle&& other) noexcept
        : brand(std::move(other.brand)), model(std::move(other.model)), year(other.year), price(other.price) {
        other.year = 0;
        other.price = 0.0f;
    }

    Motorcycle& Motorcycle::operator=(Motorcycle&& other) noexcept {
        if (this != &other) {
            brand = std::move(other.brand);
            model = std::move(other.model);
            year = other.year;
            price = other.price;
            other.year = 0;
            other.price = 0.0f;
        }
        return *this;
    }

    const std::string& Motorcycle::getBrand() const {
        return brand;
    }

    void Motorcycle::setBrand(const std::string& newBrand) {
        brand = newBrand;
    }

    const std::string& Motorcycle::getModel() const {
        return model;
    }

    void Motorcycle::setModel(const std::string& newModel) {
        model = newModel;
    }

    int Motorcycle::getYear() const {
        return year;
    }

    void Motorcycle::setYear(int newYear) {
        year = newYear;
    }

    float Motorcycle::getPrice() const {
        return price;
    }

    void Motorcycle::setPrice(float newPrice) {
        price = newPrice;
    }

    void Motorcycle::startEngine() {
        std::cout << "Pornire motor (motocicleta) - " << getBrand() << " " << getModel() << std::endl;
    }

    void Motorcycle::stopEngine() {
        std::cout << "Oprire motor (motocicleta) - " << getBrand() << " " << getModel() << std::endl;
    }

    // Implementarea clasei SportMotorcycle
    SportMotorcycle::SportMotorcycle(const std::string& brand, const std::string& model, int year, float price, int maxSpeed)
        : Motorcycle(brand, model, year, price), maxSpeed(maxSpeed) {}

    SportMotorcycle::~SportMotorcycle() {
        std::cout << "Motocicleta sport " << getBrand() << " " << getModel() << " a fost distrusă." << std::endl;
    }

    int SportMotorcycle::getMaxSpeed() const {
        return maxSpeed;
    }

    void SportMotorcycle::setMaxSpeed(int speed) {
        maxSpeed = speed;
    }

    void SportMotorcycle::startEngine() {
        std::cout << "Pornire motor (motocicleta sport) - " << getBrand() << " " << getModel() << std::endl;
    }

    void SportMotorcycle::stopEngine() {
        std::cout << "Oprire motor (motocicleta sport) - " << getBrand() << " " << getModel() << std::endl;
    }

    // Implementarea clasei MotorcycleManager
    MotorcycleManager::MotorcycleManager() {}

    MotorcycleManager::~MotorcycleManager() {
        std::cout << "Destructor pentru MotorcycleManager" << std::endl;
    }

    void MotorcycleManager::addMotorcycle(std::unique_ptr<Motorcycle> motorcycle) {
        motorcycles.push_back(std::move(motorcycle));
    }

    void MotorcycleManager::listMotorcycles() const {
        std::cout << "Lista de motociclete:\n";
        for (const auto& motorcycle : motorcycles) {
            Utilities::displayDetails(*motorcycle);
        }
    }

    void MotorcycleManager::removeMotorcycle(const std::string& brand, const std::string& model) {
        motorcycles.erase(
            std::remove_if(motorcycles.begin(), motorcycles.end(), [&](const auto& motorcycle) {
                return (motorcycle->getBrand() == brand && motorcycle->getModel() == model);
            }),
            motorcycles.end()
        );
    }

    void MotorcycleManager::updatePrices(float percentageIncrease) {
        for (auto& motorcycle : motorcycles) {
            float newPrice = motorcycle->getPrice() * (1 + percentageIncrease / 100);
            motorcycle->setPrice(newPrice);
        }
    }

}  // namespace VehicleSystem