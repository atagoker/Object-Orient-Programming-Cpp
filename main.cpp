#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Aircraft {
private:
    std::string model;
    double fuelConsumption;
    double price;

public:

    Aircraft(const std::string& model, double fuelConsumption, double price)
        : model(model), fuelConsumption(fuelConsumption), price(price) {}


    Aircraft() : model("Unknown"), fuelConsumption(0.0), price(0.0) {}


    std::string getModel() const { return model; }
    double getFuelConsumption() const { return fuelConsumption; }
    double getPrice() const { return price; }


    void setModel(const std::string& model) { this->model = model; }
    void setFuelConsumption(double fuelConsumption) { this->fuelConsumption = fuelConsumption; }
    void setPrice(double price) { this->price = price; }


    friend std::ostream& operator<<(std::ostream& os, const Aircraft& aircraft);
};

std::ostream& operator<<(std::ostream& os, const Aircraft& aircraft) {
    os << aircraft.model << ", Fuel Consumption: " << aircraft.fuelConsumption
       << ", Price: $" << std::fixed << std::setprecision(2) << aircraft.price;
    return os;
}


void printAircraftVector(const std::vector<Aircraft>& aircrafts) {
    for (std::vector<Aircraft>::const_iterator it = aircrafts.begin(); it != aircrafts.end(); ++it) {
        std::cout << *it << std::endl;
    }
}


double averagePrice(const std::vector<Aircraft>& aircrafts) {
    double sum = 0.0;
    for (std::vector<Aircraft>::const_iterator it = aircrafts.begin(); it != aircrafts.end(); ++it) {
        sum += it->getPrice();
    }
    return sum / aircrafts.size();
}

int main() {
    std::vector<Aircraft> aircrafts;
    aircrafts.push_back(Aircraft("Airbus A320", 3.1, 98000000.0));
    aircrafts.push_back(Aircraft("Boeing 737", 2.9, 102000000.0));
    aircrafts.push_back(Aircraft("Embraer E190", 2.7, 45000000.0));

    printAircraftVector(aircrafts);

    std::cout << "Average aircraft price: $" << std::fixed << std::setprecision(2) << averagePrice(aircrafts) << std::endl;

    return 0;
}
