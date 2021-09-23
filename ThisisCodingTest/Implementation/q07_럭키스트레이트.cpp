#include <iostream>
using namespace std;

int main(){
    char score [9];

    cin >> score;
    int n = strlen(score);
    int left=0, right=0;

    for (int i=0; i<n/2; i++){
        left += score[i]+'0';
    }
    for (int i=n/2; i<n; i++){
        right += score[i]+'0';
    }
    if (left == right){
        cout << "LUCKY\n";
    }else{
        cout << "READY\n";
    }
}