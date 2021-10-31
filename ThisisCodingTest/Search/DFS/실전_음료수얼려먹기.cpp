#include <iostream>
#include <vector>

using namespace std;
int n, m;
int arr[1001][1001];

void dfs(int x, int y){
    if (x > n-1 || y > m-1 || x < 0 || y < 0){
        return;
    }
    if (arr[x][y]==0){
        arr[x][y] = 1;
        dfs(x-1, y);
        dfs(x, y-1);
        dfs(x, y+1);
        dfs(x+1, y);
    }
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (arr[i][j] == 0){
                count++;
                dfs(i, j);
            }
        }
    }

    cout << count << '\n';
    
}