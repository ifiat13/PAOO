// Mycode.hpp
#ifndef MYCODE_HPP
#define MYCODE_HPP

#include <algorithm> 
#include <memory>
#include <vector>
#include <iostream>
#include <string>

namespace VehicleSystem {
    // Interfața (pure abstract class) pentru Vehicle
    class Vehicle {
    public:
        virtual ~Vehicle() = default;
        virtual void startEngine() = 0;
        virtual void stopEngine() = 0;
    };

    // Clasa de bază Motorcycle cu alocare dinamică și abstracție
    class Motorcycle : public Vehicle {
    public:
        Motorcycle(const std::string& brand, const std::string& model, int year, float price);
        virtual ~Motorcycle();

        // Rule of 5: constructor de copiere, operator de atribuire, constructor de mutare, operator de mutare
        Motorcycle(const Motorcycle& other);
        Motorcycle& operator=(const Motorcycle& other);
        Motorcycle(Motorcycle&& other) noexcept;
        Motorcycle& operator=(Motorcycle&& other) noexcept;

        // Getteri și setteri
        const std::string& getBrand() const;
        void setBrand(const std::string& brand);
        const std::string& getModel() const;
        void setModel(const std::string& model);
        int getYear() const;
        void setYear(int year);
        float getPrice() const;
        void setPrice(float price);

        void startEngine() override;
        void stopEngine() override;

    private:
        std::string brand;
        std::string model;
        int year;
        float price;
    };

    // Clasa derivată SportMotorcycle
    class SportMotorcycle : public Motorcycle {
    public:
        SportMotorcycle(const std::string& brand, const std::string& model, int year, float price, int maxSpeed);
        int getMaxSpeed() const;
        void setMaxSpeed(int speed);

        void startEngine() override;
        void stopEngine() override;

    private:
        int maxSpeed;
    };

    // Managerul de motociclete
    class MotorcycleManager {
    public:
        MotorcycleManager();
        ~MotorcycleManager();

        // Adăugare motocicletă la manager cu alocare dinamică
        void addMotorcycle(std::unique_ptr<Motorcycle> motorcycle);
        
        // Listare motociclete
        void listMotorcycles() const;

        // Ștergere motocicletă
        void removeMotorcycle(const std::string& brand, const std::string& model);

        // Actualizare prețuri
        void updatePrices(float percentageIncrease);

    private:
        std::vector<std::unique_ptr<Motorcycle>> motorcycles;
    };
}

#endif
