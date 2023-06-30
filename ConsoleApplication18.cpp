#include <iostream>
#include <string>

using namespace std;

struct Car {
    string color;
    string model;
    string number;
};

void fillCar(Car& car) {
    cout << "Enter car color: ";
    cin >> car.color;

    cout << "Enter car model: ";
    cin >> car.model;

    cout << "Enter car number (5-digit number or word up to 8 characters): ";
    cin >> car.number;
}

void printCar(const Car& car) {
    cout << "Car details:" << endl;
    cout << "Color: " << car.color << endl;
    cout << "Model: " << car.model << endl;
    cout << "Number: " << car.number << endl;
}

void editCar(Car& car) {
    cout << "Enter new car color: ";
    cin >> car.color;

    cout << "Enter new car model: ";
    cin >> car.model;

    cout << "Enter new car number: ";
    cin >> car.number;
}

void printAllCars(const Car cars[], int size) {
    cout << "All Cars:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Car " << i + 1 << ":" << endl;
        printCar(cars[i]);
        cout << endl;
    }
}

void search(const Car cars[], int size, const string& number) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (cars[i].number == number) {
            cout << "Car found at index " << i << ":" << endl;
            printCar(cars[i]);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Car with number " << number << " not found." << endl;
    }
}

int main() {
    const int numOfCars = 10;
    Car cars[numOfCars];
    int option;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1) Add a car" << endl;
        cout << "2) Edit a car by number" << endl;
        cout << "3) Search a car by number" << endl;
        cout << "0) Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;
        cout << endl;

        if (option == 1) {
            for (int i = 0; i < numOfCars; ++i) {
                if (cars[i].number.empty()) {
                    cout << "Enter details for Car " << i + 1 << ":" << endl;
                    fillCar(cars[i]);
                    cout << endl;
                    break;
                }
            }
        }
        else if (option == 2) {
            string editNumber;
            cout << "Enter car number to edit: ";
            cin >> editNumber;

            bool found = false;
            for (int i = 0; i < numOfCars; ++i) {
                if (cars[i].number == editNumber) {
                    cout << "Enter new details for Car " << i + 1 << ":" << endl;
                    editCar(cars[i]);
                    cout << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Car with number " << editNumber << " not found." << endl;
            }
        }
        else if (option == 3) {
            string searchNumber;
            cout << "Enter a car number to search: ";
            cin >> searchNumber;

            search(cars, numOfCars, searchNumber);
        }
        else if (option == 0) {
            break;
        }
        else {
            cout << "Invalid option" << endl;
        }

        cout << endl;
    }

    return 0;
}
