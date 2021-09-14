#include <iostream>
using namespace std;

enum EyeColor {Brown, Blue, Green, Gray, Other}; // 실제 값은 integer

int main()
{
    EyeColor eyeColor = Blue;
    
    switch(eyeColor){ // 정수형 체크 중
    case Brown: cout << "80% of people have Brown eyes."; break;
    case Blue: cout << "10% of people have Blue eyes.";
    case Green: cout << "2% of people have Green eyes."; break;
    case Gray: cout << "1% of people have Gray eyes."; break;
    case Other: cout << "7% of people have some other eye color."; break;
    default: cout << "Not valid eye color"; // 예외의 값 오는 경우
    }
}