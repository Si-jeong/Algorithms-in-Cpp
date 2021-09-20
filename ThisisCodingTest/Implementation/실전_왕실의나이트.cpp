#include <iostream>
#include <vector>

using namespace std;

int dx [8] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy [8] = {-1, 1, 1, -1, 2, 2, -2, -2};

int main(){
    // char 배열
    // 참고: https://ldgeao99.tistory.com/222
    
    char s[3];
    cin >> s;

    int x = s[0]-'a'+1;
    int y = s[1]-'0';

    int count = 0;

    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (1>nx || 8<nx || 1>ny || 8<ny){
            continue;
        }
        count++;
    }

    cout << count << "\n";

}