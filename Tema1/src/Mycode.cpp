#include "Mycode.hpp"
#include <iostream>
#include <vector>

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

MotorcycleManager::MotorcycleManager() {}

MotorcycleManager::~MotorcycleManager() {
    for (Motorcycle* motorcycle : motorcycles) {
        delete motorcycle;
    }
    motorcycles.clear();
}

void MotorcycleManager::addMotorcycle(const std::string& brand, const std::string& model, int year, float price) {
    Motorcycle* motorcycle = new Motorcycle(brand, model, year, price);
    motorcycles.push_back(motorcycle);
}

void MotorcycleManager::listMotorcycles() const {
    std::cout << "Lista de motociclete:\n";
    for (const Motorcycle* motorcycle : motorcycles) {
        std::cout << "Brand: " << motorcycle->getBrand() << ", Model: " << motorcycle->getModel() << ", An: " << motorcycle->getYear() << ", Preț: $" << motorcycle->getPrice() << std::endl;
    }
}

void MotorcycleManager::removeMotorcycle(const std::string& brand, const std::string& model) {
    for (size_t i = 0; i < motorcycles.size(); ++i) {
        if (motorcycles[i]->getBrand() == brand && motorcycles[i]->getModel() == model) {
            delete motorcycles[i];
            motorcycles.erase(motorcycles.begin() + i);
            break;
        }
    }
}
