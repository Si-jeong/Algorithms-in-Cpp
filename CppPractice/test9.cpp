#include <iostream>
using namespace std;

int main()
{
    int luckyNumbers[5] = {1, 3, 5, 7, 9}; 
    cout << luckyNumbers << endl;
    cout << &luckyNumbers[0] << endl;
    // 배열 이름 = 배열의 주소 = 배열의 첫 번째 원소의 주소
    cout << luckyNumbers[0] << endl;

    int * luckyPointer = luckyNumbers;
    cout << "Pointing to " << luckyPointer << ", value: " << *luckyPointer << endl;
    luckyPointer++; // 포인터가 두 번째 원소로 움직임
    cout << "Pointing to " << luckyPointer << ", value: " << *luckyPointer << endl;
    // 주의할 점: 포인터가 인덱스 밖 값을 가리키면 이슈 발생
}