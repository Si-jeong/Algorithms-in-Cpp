// Object-oriented programming (OOP, 객체지향 프로그램)
// 1. encapsulation: properties should not be public -> private
// 2. inheritance
// 3. polymorphism

// 1. encapsulation
#include <iostream>
using namespace std;

class Car {
private: // hidden properties from users.
    string Name;
    string Color;
    double Price;
    bool IsBroken;
public: // expose methods user can invoke.
    Car(string name, string color, double price){
        Name = name;
        Color = color;
        Price = price;
        IsBroken = false;
    }
    void getInfo(){
        cout << "Name: " << Name << endl;
        cout << "Color: " << Color << endl;
        cout << "Price: " << Price << "$" << endl;
    }
    void crashCar(){
        cout << Name << " crashed" << endl;
        IsBroken = true;
    }
    void repairCar(){
        cout << Name << " repaired" << endl;
        IsBroken = false;
    }
    void move(){
        if(IsBroken)
            cout << Name << " is broken" << endl;
        else
            cout << Name << " is driving" << endl;
    }
};

int main()
{
    Car ford("Ford", "red", 50000);
    Car volvo("Volvo", "black", 70000);

    ford.move();
    ford.crashCar();
    ford.move();
    ford.repairCar();
    ford.move();

}