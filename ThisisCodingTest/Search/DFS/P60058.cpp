#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//올바른 괄호 문자열인지?
bool check(string s){
    int count = 0;
    for (int i=0; i<s.size(); i++){
        if (s[i] == '(') count++;
        else{
            if (count == 0) {
                return false;
            }
            count--;
        }
    }
    return true;
}

string dfs(string p){
    string result = "";
    if (p.size() == 0) {
        return result;
    }

    for(int i=0, count=0; i<p.size(); i++){

        if (p[i] == '(') count++;
        else count--;
        
        if(count==0){
            string u = p.substr(0, i+1);
            string v = p.substr(i+1);

            // 올바른 문자열
            if (check(u)){
                result += u + dfs(v);
                return result;
            }
            // 올바른 괄호 문자열 아님
            else{
                result += "(" + dfs(v) + ")";
                //reverse(u.begin(), u.end()); // 뒤집으라는 의미는 순서가 아니라, 문자를 바꿔라는 뜻...!
                for (int j=1; j<u.size()-1; j++){
                    if (u[j] == '(') u[j] = ')';
                    else u[j] = '(';
                }
                result += u.substr(1, u.size()-2);
                return result;
            }
        }
    }
}

string solution(string p) {
    return dfs(p);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string p;

    p = "()))((()";
    cout << solution(p) << "\n";

    return 0;
}