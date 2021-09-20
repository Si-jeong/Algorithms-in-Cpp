#include <iostream>
#include <string>

using namespace std;

int n;

int main(){
    cin >> n;
    int st = 0;
    if(n/6==0){
        st = (10*6*10*2 + 6*6*10*2) - (6*10*4 + 6*6 + 10*10) + (10*2 + 6*2) - 1;
    }
    else{
        st = 6*6*10*2-6*6;
    }

    int result = st*n + 60*60;

    cout << result << "\n";


}