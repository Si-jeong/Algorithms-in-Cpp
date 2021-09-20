#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<string> dir = {"R", "L", "U", "D"}; 

int main(){
    
    cin >> n;
    cin.ignore(); // 버퍼 비우기
    // 참고: https://jhnyang.tistory.com/107

    string moves;
    getline(cin, moves); // 공백 포함 문자열 입력 받기

    istringstream ss(moves);
    // 참고:  https://greenapple16.tistory.com/219

    int x = 1;
    int y = 1;
    string move;
    while(getline(ss, move, ' ')){ // string 공백 단위로 구분
        int idx = find(dir.begin(), dir.end(), move) - dir.begin();
        // vector 요소의 인덱스 찾기
        // 참고: https://notepad96.tistory.com/entry/C-Vector-%EA%B0%92-%ED%83%90%EC%83%89-find-%EC%A1%B4%EC%9E%AC-%EC%9C%A0%EB%AC%B4-%ED%99%95%EC%9D%B8
        int nx = x + dx[idx];
        int ny = y + dy[idx];
        if (nx<1 || nx>n || ny<1 || ny>n){
            continue;
        }
        x = nx; y = ny;
    }
    cout << x << " " << y << "\n";

}