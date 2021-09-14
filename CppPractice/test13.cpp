// Object-oriented programming (OOP, 객체지향 프로그램)
// 1. encapsulation
// 2. inheritance
// 3. polymorphism

#include <iostream>
using namespace std;

// 3. polymorphism

// Access modifiers
// 1. private: properties를 오직 이 클래스 안에서만 접근 가능 (default)
// 2. public: properties를 클래스 바깥에서 접근 가능
// 3. protected: properties를 derived class에서 접근 가능
class Car {
private:
    string Color;
    double Price;
protected:
    string Name;
    bool IsBroken;
public:
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

class FlyingCar :public Car{
public:
    FlyingCar(string name, string color, double price):Car(name, color, price) {
    }
    void move(){
        if(IsBroken)
            cout << Name << " is broken" << endl;
        else
            cout << Name << " is flying" << endl; // diffent implementation
    }
};
class UnderwaterCar :public Car{
public:
    UnderwaterCar(string name, string color, double price):Car(name, color, price) {
    }
    void move(){
        if(IsBroken)
            cout << Name << " is broken" << endl;
        else
            cout << Name << " is diving" << endl;
    }
};

int main()
{
    Car ford("Ford", "red", 50000);
    FlyingCar flyingCar("Sky Fury", "black", 500000);
    UnderwaterCar underwaterCar("Sea Storm", "blue", 600000);

    ford.move();
    flyingCar.move();
    underwaterCar.move();

    // 포인터로 객체의 method를 호출
    Car* car1 = &flyingCar;
    Car* car2 = &underwaterCar;

    // envoke method using pointer: ->
    car1 -> crashCar(); 
    car2 -> crashCar();

    ford.move();
    flyingCar.move();
    underwaterCar.move();

    car1 -> repairCar(); 
    car2 -> repairCar();
    
    ford.move();
    flyingCar.move();
    underwaterCar.move();
}