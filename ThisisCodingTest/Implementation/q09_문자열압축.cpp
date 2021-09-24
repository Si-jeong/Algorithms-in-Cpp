// 다시 풀기!!

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s){
    int l = s.length();
    
    int answer = l;

    for (int i=l/2; i>1; i--){ // 단위
        int tem = 0;
        int cnt = 0;
        for (int j=0; j<l; j++){
            if (j+2*i >= l) {
                tem += l-j;
                break;
            }
            if (s.substr(j, j+i).compare(s.substr(j+i, j+2*i))==0){
                j+=i-1;
                cnt++;

            }else if(cnt!=0){
                tem += to_string(cnt).length() + i + 1;
                cnt = 0;
            }else{
                cnt = 0;
                tem += 1;
            }
        }
        cout << tem << "\n";
        answer = (answer>tem) ? tem : answer;
    }
    return answer;

}


int main(){
    string input_string;

    cin >> input_string;

    cout << solution(input_string) << "\n";
}