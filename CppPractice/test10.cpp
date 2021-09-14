// Object-oriented programming (객체지향 프로그램)
#include <iostream>
using namespace std;

class Car {
public: // 클래스 멤버는 private가 default -> 클래스 밖에서 멤버에 접근하기 위해 public
    // Attributes
    string Name;
    string Color;
    double Price;

    // Constructor
    // 1. return 타입 없음
    // 2. 클래스 이름과 같음
    Car(string name, string color, double price){
        Name = name;
        Color = color;
        Price = price;
    }

    // A class method
    void getInfo(){
        cout << "Name: " << Name << endl;
        cout << "Color: " << Color << endl;
        cout << "Price: " << Price << "$" << endl;
    }

};

int main()
{
    Car myCar("Ford", "red", 50000);
    Car myCar2("Volvo", "black", 70000);

    myCar.getInfo();
    myCar.getInfo();
}