#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int n, m;
    cin >> n >> m;
    int map[n][m];
    int x, y, dir;

    cin >> x >> y >> dir;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            // cout << map[i][j] << " ";
        }
        // cout << "\n";
    }

    int count = 0;

    while(true){
        bool isLand = false;
        for(int i=1; i<=4; i++){
            int ndir = (dir-i) % 4;
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];

            if (nx<0 || nx>n-1 || ny<0 || ny>m-1){
                continue;
            }
            if (map[nx][ny]==1 || map[nx][ny]==-1){
                continue;
            }
            isLand = true; // 방문하지 않은 육지
            map[nx][ny] = -1; // 방문
            count++;
            x = nx; // 이동
            y = ny; 
            dir = ndir; 
            break;
        }
        if (!isLand){
            int nx = x - dx[dir];
            int ny = y - dy[dir];
            if ((nx<0 || nx>n-1 || ny<0 || ny>m-1) || map[nx][ny]==1){
                break;
            }
            x = nx;
            y = ny;
        }
    }
    cout << count << "\n";


}