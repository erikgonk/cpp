#include <iostream>

class Vehicle {
private:
    int wheels;
    std::string motor;
    std::string structure;

public:
    // Constructor with parameters
 //   Vehicle(int w, std::string m, std::string s) : wheels(w), motor(m), structure(s) {}
 	Vehicle();
    void displayInfo() {
        std::cout << "Wheels: " << wheels << ", Motor: " << motor << ", Structure: " << structure << std::endl;
    }
};

Vehicle::Vehicle() : wheels(4), motor("V8"), structure("to flama") {}

int main() {
    // Creating a car (4 wheels, car motor, car structure)
    Vehicle car(4, "Car Motor", "Car Body");
    car.displayInfo();

    // Creating a motorbike (2 wheels, bike motor, bike structure)
    Vehicle motorbike(2, "Bike Motor", "Bike Frame");
    motorbike.displayInfo();

    return 0;
}
