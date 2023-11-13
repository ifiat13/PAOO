// Utilities.hpp
#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <memory>
#include <vector>

namespace Utilities {

    // Funcție template pentru afișarea detaliilor unui obiect Vehicle
    template <typename T>
    void displayDetails(const T& vehicle) {
        std::cout << "Brand: " << vehicle.getBrand() << ", Model: " << vehicle.getModel() << ", An: "
                  << vehicle.getYear() << ", Preț: $" << vehicle.getPrice() << std::endl;
    }

    // Funcție template pentru afișarea elementelor unei colecții
    template <typename T>
    void displayCollection(const std::vector<T>& collection) {
        for (const auto& item : collection) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    // Funcție template pentru afișarea elementelor unui array
    template <typename T, std::size_t N>
    void displayArray(const T (&arr)[N]) {
        for (const auto& item : arr) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    // Funcție template pentru gestionarea unui unique pointer
    template <typename T>
    std::unique_ptr<T> makeUnique(T* ptr) {
        return std::unique_ptr<T>(ptr);
    }

    // Funcție template pentru gestionarea unui shared pointer
    template <typename T>
    std::shared_ptr<T> makeShared(T* ptr) {
        return std::shared_ptr<T>(ptr);
    }

}  // namespace Utilities

#endif