#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;
int n, m;
int maze[201][201];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push({x, y});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
                continue;
            if (maze[nx][ny] == 0) 
                continue;
            if (maze[nx][ny] == 1) {
                maze[nx][ny] = maze[x][y] + 1;
                q.push({nx, ny});
            } 
        }
    }
    return maze[n - 1][m - 1];
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }
    cout << bfs(0, 0) << '\n';

}