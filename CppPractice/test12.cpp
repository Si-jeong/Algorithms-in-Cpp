// Object-oriented programming (OOP, 객체지향 프로그램)
// 1. encapsulation
// 2. inheritance
// 3. polymorphism

#include <iostream>
using namespace std;

class Car {
private:
    string Name;
    string Color;
    double Price;
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

// 2. inheritance
// derived class, base class
class FlyingCar :public Car{
    // derived constructor 생성하기 (public: 클래스 밖에서 접근할 수 있게 하기 위해)
    // base class의 constructor 상속
public:
    FlyingCar(string name, string color, double price):Car(name, color, price) {

    }
};

int main()
{
    Car ford("Ford", "red", 50000);
    // Derived Class 만의 public constructor 만들어줘야 함
    FlyingCar flyingCar("Sky Fury", "black", 500000);

    // Derived Class의 객체도 base class의 public method에 접근 가능
    flyingCar.getInfo();


}