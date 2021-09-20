#include <iostream>

using namespace std;

int n, k, result;

int main(){
    cin >> n >> k;

    while(n > 1){
        if(n % k == 0){
            n /= k;
        }
        else{
            n--;
        }
        result++;
    }

    cout << result << endl;
}