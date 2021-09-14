#include <iostream>
using namespace std;

// function decoration: before main()
float sum(float a, float b); 
void introduceMe(string name, int age=0); 
// return 값 없는 함수 void
// 디폴트 파라미터 값 설정

int main()
{
    cout << sum(2.2, 5) << endl;
    cout << sum(5.2, 3) << endl;
    cout << sum(4, 8) << endl;
    introduceMe("mmm", 20);
    introduceMe("lll");
}

// function definition: after main()
float sum(float a, float b){
    return a + b;
}

void introduceMe(string name, int age) {
    cout << "My name is " << name << endl;
    cout << "I am " << age << " years old" << endl;
}