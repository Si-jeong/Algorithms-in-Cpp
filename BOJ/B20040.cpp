#include <iostream>
#include <vector>

using namespace std;

// 참고: https://jackpot53.tistory.com/92


int find_parent(vector<int>& parents, int a){
    int p = a;
    while (parents[p] != p){
        p = parents[p];
    }
    return p;
}

bool checkCycle(vector<int>& parents, int a, int b){
    int u = find_parent(parents, a);
    int v = find_parent(parents, b);
    if (u == v) {
        return true;
    }
    else if (u < v){
        parents[v] = u;
    }
    else{
        parents[u] = v;
    }
    return false;
}
int main(){
    int n, m; 
    int ans=0;
    vector<int> parents;

    cin >> n >> m;

    for(size_t i=0; i<n; i++){
        parents.push_back(i);
    }

    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if (checkCycle(parents, a, b)){
            ans = i+1;
            break;
        }
    }
    cout << ans << "\n";

}
// 어려웠던 점: 
// c++ 로 union-find 구현 어려웠다. 
// 사이클의 조건에서 모든 선분이라는 조건이 헷갈렸다.
// vector의 값을 함수 안에서 변경하려면 call by reference 해야 함.
// 참고: https://soyoonique.tistory.com/32, https://www.acmicpc.net/board/view/38804