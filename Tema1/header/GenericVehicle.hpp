// GenericVehicle.hpp

#ifndef GENERIC_VEHICLE_HPP
#define GENERIC_VEHICLE_HPP

#include <string>

// Definirea unei clase template GenericVehicle
template <typename T>
class GenericVehicle {
public:
    GenericVehicle(const std::string& brand, const std::string& model, int year, T price)
        : brand(brand), model(model), year(year), price(price) {}

    const std::string& getBrand() const {
        return brand;
    }

    void setBrand(const std::string& newBrand) {
        brand = newBrand;
    }

    const std::string& getModel() const {
        return model;
    }

    void setModel(const std::string& newModel) {
        model = newModel;
    }

    int getYear() const {
        return year;
    }

    void setYear(int newYear) {
        year = newYear;
    }

    T getPrice() const {
        return price;
    }

    void setPrice(T newPrice) {
        price = newPrice;
    }

private:
    std::string brand;
    std::string model;
    int year;
    T price;
};

#endif // GENERIC_VEHICLE_HPP