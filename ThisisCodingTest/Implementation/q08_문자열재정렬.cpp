#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(){
    // char input_string [10001];
    string input_string;
    // vector<char> characters;
    cin >> input_string;
    
    // 문자열 문자 정렬
    sort(input_string.begin(), input_string.end(), [] (auto &c1, auto &c2) {return c1<c2;});
    
    int sum_num = 0;
    int i=0;
    for(; i<input_string.length(); i++){
        int c = input_string[i]-'0';
        if(c>=0 && c<=9){
            sum_num += c;
        }
        else{
            break;
        }
    }
    
    // 문자열 슬라이싱
    cout << input_string.substr(i, input_string.length()) << sum_num << "\n";


}