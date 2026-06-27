#include <iostream>
#include <string>


// PARENT CLASS — blueprint for ALL vehicles
// contains data that every vehicle type shares

class Vehicle {
protected:
    // protected = this class AND its children can access
    // outsiders (main) cannot touch directly
    std::string make;   
    std::string model;  
    float speed;        

public:
    // runs automatically when Vehicle object is created
    Vehicle(std::string initMake, std::string initModel, float initSpeed) {
        make  = initMake;
        model = initModel;
        speed = initSpeed;
    }

    // virtual = children are ALLOWED to replace this function
    virtual void display() {
        std::cout << make << " | " << model << " | " << speed << " km/h" << std::endl;
    }
};


// CHILD CLASS 1 — Car
// inherits everything from Vehicle, adds numDoors
class Car : public Vehicle {
private:
    int numDoors;  // only Cars have doors — private, nobody else needs it

public:
    // 4 params: 3 passed up to Vehicle, 1 stays in Car
    Car(std::string initMake, std::string initModel, float initSpeed, int initDoors)
        : Vehicle(initMake, initModel, initSpeed)  // parent sets up first
    {
        numDoors = initDoors;  // Car handles its own extra data
    }

    // override = replacing Vehicle's display() with Car's own version
    void display() override {
        // make/model/speed from Vehicle (protected)
        // numDoors from Car's own private variable
        std::cout << make  << " | " << model << " | "
                  << speed << " km/h | Doors: " << numDoors
                  << std::endl;
    }
};

class Motorcycle:public Vehicle{
    private:
        bool sidecar;
    public:
        Motorcycle(std::string initMake, std::string initModel, float initSpeed, bool initSidecar)
        :Vehicle(initMake,initModel,initSpeed){
            sidecar=initSidecar;
        }
    void display() override{
         std::cout << make  << " | " << model << " | "
                  << speed << " km/h | Sidecar: " << (sidecar ? "Yes":"No")
                  << std::endl;
    }
    
};

    
int main() {
    int choice;
    std::string make;
    std::string model;
    float speed;
    int doors;
    bool sidecar;
    int num;
    
    

    std::cout<<"How many vehicles you would like to add?: ";
    std::cin>>num;

    Vehicle* vehicles[num];

    // STEP 1 — ask choice
    for (int k=0;k<num;k++){
    std::cout << "Make a selection: 1 for car and 2 for motorcycle: ";
    std::cin >> choice;
    std::cin.ignore();

    // STEP 2 — validate FIRST, exit if invalid
    if (choice != 1 && choice != 2) {
        std::cout << "Invalid selection!" << std::endl;
        return 0;
    }

    // STEP 3 — ask common info (only valid choices reach here)
    std::cout << "Make: ";
    std::getline(std::cin, make);

    std::cout << "Model: ";
    std::getline(std::cin, model);

    std::cout << "Speed: ";
    std::cin >> speed;

    // STEP 4 — branch based on choice
    if (choice == 1) {
        std::cout << "How many doors: ";
        std::cin >> doors;
        vehicles[k] = new Car(make, model, speed, doors);
    }
    else {
        std::cout << "Does it have sidecar? 1 for Yes 0 for No: ";
        std::cin >> sidecar;
        vehicles[k] = new Motorcycle(make, model, speed, sidecar);
    }

    }
    for (int k = 0; k < num; k++) {
    vehicles[k]->display();
}

    for (int k = 0; k < num; k++) {
    delete vehicles[k];
}
    return 0;
}
