#include <iostream>
using namespace std;

int main()
{
    bool isTodaySunny = true;
    bool isTodayWeekend = true;

    // if (isTodayWeekend && isTodaySunny) {
    //     cout << "Go to the park" << endl;
    // }
    // else if(isTodayWeekend && !isTodaySunny){
    //     cout << "Go to the park, but take an umbrella" << endl;
    // }
    // else{
    //     cout << "Go to work" << endl;
    // }

    if (isTodayWeekend) {
        if(isTodaySunny)
            cout << "Go to the park" << endl;
        else
            cout << "Go to the park, but take an umbrella" << endl;
    }
    else
        cout << "Go to work" << endl;

    // isTodaySunny ? cout << "Go to the park" : cout << "Take an umbrella";

}
