#include "Mycode.hpp"
#include <iostream>
#include <algorithm>

// Implementare pentru clasa Motorcycle

Motorcycle::Motorcycle(const std::string& brand, const std::string& model, int year, float price)
    : brand(brand), model(model), year(year), price(price), newVehicle(true) {}

Motorcycle::Motorcycle(const Motorcycle& other)
    : brand(other.brand), model(other.model), year(other.year), price(other.price), newVehicle(other.newVehicle) {}

Motorcycle::Motorcycle(Motorcycle&& other) noexcept
    : brand(std::move(other.brand)), model(std::move(other.model)), year(other.year), price(other.price), newVehicle(other.newVehicle) {
    other.year = 0;
    other.price = 0.0f;
    other.newVehicle = false;
}

Motorcycle::Motorcycle(const std::string& brand, const std::string& model, int year, float price, bool isNew)
    : brand(brand), model(model), year(year), price(price), newVehicle(isNew) {}

Motorcycle& Motorcycle::operator=(const Motorcycle& other) {
    if (this == &other) {
        return *this;
    }

    brand = other.brand;
    model = other.model;
    year = other.year;
    price = other.price;
    newVehicle = other.newVehicle;
    return *this;
}

Motorcycle& Motorcycle::operator=(Motorcycle&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    brand = std::move(other.brand);
    model = std::move(other.model);
    year = other.year;
    price = other.price;
    newVehicle = other.newVehicle;

    other.year = 0;
    other.price = 0.0f;
    other.newVehicle = false;

    return *this;
}

Motorcycle::~Motorcycle() {
    std::cout << "Motocicleta " << brand << " " << model << " a fost distrusă." << std::endl;
}

const std::string& Motorcycle::getBrand() const {
    return brand;
}

const std::string& Motorcycle::getModel() const {
    return model;
}

int Motorcycle::getYear() const {
    return year;
}

float Motorcycle::getPrice() const {
    return price;
}

bool Motorcycle::isNew() const {
    return newVehicle;
}

void Motorcycle::updatePrice(float newPrice) {
    price = newPrice;
}

// Implementare pentru clasa MotorcycleManager

MotorcycleManager::MotorcycleManager() {}

MotorcycleManager::~MotorcycleManager() {
    std::cout << "Destructor pentru MotorcycleManager" << std::endl;
}

void MotorcycleManager::addMotorcycle(Motorcycle motorcycle) {
    motorcycles.push_back(std::move(motorcycle));
}

void MotorcycleManager::listMotorcycles() const {
    std::cout << "Lista de motociclete:\n";
    for (const Motorcycle& motorcycle : motorcycles) {
        std::cout << "Brand: " << motorcycle.getBrand() << ", Model: " << motorcycle.getModel() << ", An: " << motorcycle.getYear() << ", Preț: $" << motorcycle.getPrice();
        if (motorcycle.isNew()) {
            std::cout << " (Nouă)";
        }
        std::cout << std::endl;
    }
}

void MotorcycleManager::removeMotorcycle(const std::string& brand, const std::string& model) {
    motorcycles.erase(std::remove_if(motorcycles.begin(), motorcycles.end(), [brand, model](const Motorcycle& motorcycle) {
        return motorcycle.getBrand() == brand && motorcycle.getModel() == model;
    }), motorcycles.end());
}

void MotorcycleManager::updatePrices(float percentageIncrease) {
    for (Motorcycle& motorcycle : motorcycles) {
        float newPrice = motorcycle.getPrice() * (1 + percentageIncrease / 100);
        motorcycle.updatePrice(newPrice);
    }
}