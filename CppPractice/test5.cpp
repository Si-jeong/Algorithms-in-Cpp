#include <iostream>
using namespace std;

int main()
{
    cout << "WHILE:\n";
    int counter = 11;
    while(counter<=10){
        cout << counter << endl;
        counter++;
    }

    // 처음 값이 거짓이여도 do while문은 실행
    cout << "DO-WHILE:\n";
    int doWhileCounter = 11;
    do{
        cout << doWhileCounter << endl;
        doWhileCounter++;
    }while (doWhileCounter <= 10);
}