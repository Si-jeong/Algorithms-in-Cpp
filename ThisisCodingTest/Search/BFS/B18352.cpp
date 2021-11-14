#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, x;
vector<int> graph[300001];
int dist[300001];

void bfs (int s){
    queue <int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();

        for (int i=0; i<graph[now].size(); i++){
            int next = graph[now][i];
            if (dist[next] != -1) continue;
            dist[next] = dist[now] + 1; // 최단 거리 갱신
            q.push(next);
        }
    }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k >> x;
    for (int i=0, a, b; i<m; i++){
        cin >> a >> b;
        graph[a-1].push_back(b-1);
    }
    fill(dist, dist+n, -1);

    bfs(x-1);

    bool exist = false;
    for (int i=0; i<n; i++){
        if (dist[i]==k){
            cout << i+1 << '\n';
            exist = true;
        }
    }
    if (!exist) cout << -1 << '\n';

}