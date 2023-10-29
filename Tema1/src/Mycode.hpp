#ifndef MYCODE_HPP
#define MYCODE_HPP

#include <string>
#include <vector>

class Motorcycle {
public:
    Motorcycle(const std::string& brand, const std::string& model, int year, float price);
    ~Motorcycle();

    // Copy constructor
    Motorcycle(const Motorcycle& other);

    // Operator de atribuire
    Motorcycle& operator=(const Motorcycle& other);

    const std::string& getBrand() const;
    const std::string& getModel() const;
    int getYear() const;
    float getPrice() const;

private:
    std::string brand;
    std::string model;
    int year;
    float price;
};

class MotorcycleManager {
public:
    MotorcycleManager();
    ~MotorcycleManager();

    // Adaugarea unei motociclete
    void addMotorcycle(const std::string& brand, const std::string& model, int year, float price);

    // Afișarea motocicletelor
    void listMotorcycles() const;

    // Ștergerea unei motociclete după brand și model
    void removeMotorcycle(const std::string& brand, const std::string& model);

private:
    std::vector<Motorcycle*> motorcycles;
};

#endif
