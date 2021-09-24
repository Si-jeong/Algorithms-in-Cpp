// 다시 풀기!!

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s){
    int l = s.length();
    
    int answer = l;

    for (int i=l/2; i>1; i--){ // 단위
        string tem;
        int cnt = 0;
        for (int j=0; j<l; j++){
            size_t pos;
            pos = s.find(s.substr(j, j+i));
        
        }
    }
    return answer;

}


int main(){
    string input_string;

    cin >> input_string;

    cout << solution(input_string) << "\n";
}