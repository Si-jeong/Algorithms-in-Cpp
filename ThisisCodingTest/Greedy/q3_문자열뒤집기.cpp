#include <iostream>

using namespace std;

string str;
int result;

int main(){
    cin >> str;
    
    char c = str[0];
    int count = 0;


    for (int i=1; i<str.size(); i++){
        if (str[i] != c){
            c = str[i];
            count++;
        }        
    }
    result = count/2;
    if (count % 2){
        result++;
    }
    cout << result << endl;

}