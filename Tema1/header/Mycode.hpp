// Mycode.hpp
#ifndef MYCODE_HPP
#define MYCODE_HPP

#include "Utilities.hpp"
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

        // Getteri și setteri pentru variabilele private
        virtual const std::string& getBrand() const = 0;
        virtual void setBrand(const std::string& brand) = 0;
        virtual const std::string& getModel() const = 0;
        virtual void setModel(const std::string& model) = 0;
        virtual int getYear() const = 0;
        virtual void setYear(int year) = 0;
        virtual float getPrice() const = 0;
        virtual void setPrice(float price) = 0;
    };

    // Clasa de bază Motorcycle cu alocare dinamică și abstracție
    class Motorcycle : public Vehicle {
    public:
        // Constructor cu inițializare
        Motorcycle(const std::string& brand, const std::string& model, int year, float price);

        // Destructor pentru eliberarea heap-ului
        ~Motorcycle();

        // Copy constructor
        Motorcycle(const Motorcycle& other);

        // Operator de atribuire
        Motorcycle& operator=(const Motorcycle& other);

        // Move constructor
        Motorcycle(Motorcycle&& other) noexcept;

        // Move operator de atribuire
        Motorcycle& operator=(Motorcycle&& other) noexcept;

        // Getteri și setteri
        const std::string& getBrand() const override;
        void setBrand(const std::string& newBrand) override;
        const std::string& getModel() const override;
        void setModel(const std::string& newModel) override;
        int getYear() const override;
        void setYear(int newYear) override;
        float getPrice() const override;
        void setPrice(float newPrice) override;

        // Funcții de start și oprire a motorului
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
        // Constructor cu inițializare
        SportMotorcycle(const std::string& brand, const std::string& model, int year, float price, int maxSpeed);

        // Destructor pentru eliberarea heap-ului
        ~SportMotorcycle();

        // Funcții de start și oprire a motorului specific sport
        void startEngine() override;
        void stopEngine() override;

        // Getter și setter pentru variabila specifică SportMotorcycle
        int getMaxSpeed() const;
        void setMaxSpeed(int speed);

    private:
        int maxSpeed;
    };

    class Person {
    public:
        Person(const std::string& name) : name(name) {}

        const std::string& getName() const {
            return name;
        }

        void addMotorcycle(std::shared_ptr<Motorcycle> motorcycle);

        void displayMotorcycles() const;

    private:
        std::string name;
        std::vector<std::shared_ptr<Motorcycle>> motorcycles;
    };
    
    // Managerul de motociclete
    class MotorcycleManager {
    public:
        // Constructor cu inițializare
        MotorcycleManager();

        // Destructor pentru eliberarea heap-ului
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
        // Vector pentru stocarea motocicletelor cu unique pointer
        std::vector<std::unique_ptr<Motorcycle>> motorcycles;
    };

}  // namespace VehicleSystem

#endif