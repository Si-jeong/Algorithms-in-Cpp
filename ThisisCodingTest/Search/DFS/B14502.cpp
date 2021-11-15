#include <iostream>
#include <vector>
#include <queue>


using namespace std;
int graph[8][8];
int virus[8][8];
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans=-1;

void spread(int x, int y){
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (virus[nx][ny] == 0) {
                virus[nx][ny] = 2;
                spread(nx, ny);
            }
        }
    }
}

// 벽 세우기
void dfs(int count){

    // 벽 3 개
    if (count == 3){
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                virus[i][j] = graph[i][j];
            }
        }
        // 바이러스 전파
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (virus[i][j] == 2) {
                    spread(i, j);
                }
            }
        }
        // 안전 영역 크기 구하기
        int size = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (virus[i][j] == 0) {
                    size += 1;
                }
            }
        }
        if (ans < size) ans = size;
        return;
    }
    // 벽 설치
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (graph[i][j] == 0) {
                graph[i][j] = 1;
                dfs(count+1);
                graph[i][j] = 0;
            }
        }
    }

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector <int> s;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> graph[i][j];
        }

    }

    dfs(0);
    cout << ans << '\n';
    return 0;
}