#include <iostream>
#include <queue>

using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    queue <pair <int, int> > q; // 뱀 위치
    int n, k;
    cin >> n >> k;

    // 이차원 벡터 선언 및 초기화
    vector <vector <int> > board(n, vector <int>(n, 0));

    for (int i=0; i<k; i++){
        int row, col;
        cin >> row >> col;
        board[row-1][col-1] = 1; // 사과
    }

    // // 디버깅
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<n; j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int l;
    cin >> l;
    
    int x = 0;
    int y = 0;
    q.push(pair<int,int>(0, 0));
    
    int time = 0;
    int dir = 0;
    for (int i=0; i<=l; i++){
        int mvSec;
        char mvDir;
        if (i<l){
            cin >> mvSec >> mvDir;
        }
        else{
            mvSec = time+n;
        }
        int move = mvSec - time;
        bool isEnd = false;
        // 방향 틀 때까지 이동
        for(int j=0; j<move; j++){
            time++;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            // cout << "nx, ny : " << nx << ", " << ny << "\n";
            if (0>nx || 0>ny || n-1<nx || n-1<ny){ // 벽
                // cout << "case 1\n";
                // // 디버깅
                // for (int i=0; i<n; i++){
                //     for (int j=0; j<n; j++){
                //         cout << board[i][j] << " ";
                //     }
                //     cout << "\n";
                // }

                isEnd = true;
                break;
            }
            if (board[nx][ny] == -1){ // 방문 중
                // cout << "case 2\n";
                // // 디버깅
                // for (int i=0; i<n; i++){
                //     for (int j=0; j<n; j++){
                //         cout << board[i][j] << " ";
                //     }
                //     cout << "\n";
                // }
                isEnd = true;
                break;
            }
            else if (board[nx][ny] == 0){ // 사과 없음
                // 꼬리 방문 취소

                board[q.front().first][q.front().second] = 0;
                q.pop();
            }

            x = nx; y = ny;
            board[nx][ny] = -1; //방문 표시
            q.push(pair<int, int>(nx, ny)); // 방문
            
            // cout << "case 3\n";
            // // 디버깅
            // for (int i=0; i<n; i++){
            //     for (int j=0; j<n; j++){
            //         cout << board[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
        }

        if (isEnd){
            cout << time << "\n";
            break;
        }
        // 끝 아닐 시 방향 변경
        if (mvDir=='D'){
            dir = (dir+1)%4;
        }else if (mvDir=='L'){
            if (dir == 0){
                dir = 3;
            }
            else{
                dir = (dir-1)%4;
            }
        }
    }
}