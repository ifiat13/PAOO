#ifndef MYCODE_HPP
#define MYCODE_HPP

#include <string>
#include <vector>

class Motorcycle {
public:
    Motorcycle(const std::string& brand, const std::string& model, int year, float price);
    Motorcycle(const Motorcycle& other); // Copy constructor
    Motorcycle(Motorcycle&& other) noexcept; // Move constructor
    Motorcycle(const std::string& brand, const std::string& model, int year, float price, bool isNew); // Constructor suplimentar
    Motorcycle& operator=(const Motorcycle& other); // Copy assignment operator
    Motorcycle& operator=(Motorcycle&& other) noexcept; // Move assignment operator
    ~Motorcycle();

    const std::string& getBrand() const;
    const std::string& getModel() const;
    int getYear() const;
    float getPrice() const;
    bool isNew() const; // Metodă pentru a verifica dacă motocicleta este nouă
    void updatePrice(float newPrice); // Funcționalitate nouă

private:
    std::string brand;
    std::string model;
    int year;
    float price;
    bool newVehicle;
};

class MotorcycleManager {
public:
    MotorcycleManager();
    ~MotorcycleManager();

    void addMotorcycle(Motorcycle motorcycle); // Utilizarea constructorului de mutare în loc de referință const
    void listMotorcycles() const;
    void removeMotorcycle(const std::string& brand, const std::string& model);
    void updatePrices(float percentageIncrease); // Funcționalitate nouă

private:
    std::vector<Motorcycle> motorcycles;
};

#endif