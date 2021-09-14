// 포인터: Address of variable
// 1. 함수에서 변수 공유할 때
// 2. 배열

// 1. 함수에서 변수 공유할 때
#include <iostream>
using namespace std;

void celebrateBirthday(int* age);

int main()
{
    int myAge = 25;
    cout << "Before function, age: " << myAge << endl;
    celebrateBirthday(&myAge);
    cout << "After function, age: " << myAge << endl;


}
void celebrateBirthday(int* age){
    (*age)++;
    cout << "Yeeeey, celebrated " << *age << ". birthday" << endl;
}