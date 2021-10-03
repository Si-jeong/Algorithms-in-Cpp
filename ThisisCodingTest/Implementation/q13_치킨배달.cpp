// #include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> //abs
// #include <numeric>
#include <stdio.h> //scanf, printf
using namespace std;

int main(){
    int n, m;
    // vector<vector<int> > graph;
    // cin >> n >> m;
    scanf("%d %d", &n, &m);
    vector<pair<int, int> > chicken;
    vector<pair<int, int> > house;
    // vector<int> distance;
    for (int i=0; i<n; i++){
        // vector <int> v;
        for (int j=0; j<n; j++){
            int t;
            scanf("%d", &t);
            // cin >> t;
            // v.push_back(t);
            if (t == 2){
                chicken.push_back({i, j}); // 치킨 집 위치 저장
            }
            else if (t == 1){
                house.push_back({i, j}); // 집 위치 저장
            }
        }
        // graph.push_back(v);
    }

    // for (int i=0; i<chicken.size(); i++){
    //     int x = chicken[i].first;
    //     int y = chicken[i].second;
    //     int d = 0;
    //     for (int j=0; j<house.size(); j++){
    //         int p = house[j].first;
    //         int q = house[j].second;
    //         d += abs(x-p) + abs(y-q);
    //     }
    //     distance.push_back(d);
    // }
    // sort(distance.begin(), distance.end());
    // // cout << accumulate(distance.begin(), distance.begin()+m, 0);
    // cout << distance[0];

    vector<bool> v (chicken.size()-m, false);
    v.insert(v.end(), m, true);
    int ans = 250000;
    do{
        int cityD = 0;
        for (int i=0; i<house.size(); i++){
            int minV = 101;
            for (int j=0; j<chicken.size(); j++){
                if (v[j]){
                    int d = abs(house[i].first-chicken[j].first) + abs(house[i].second-chicken[j].second);
                    if (minV > d) minV = d;
                }
            }
            cityD += minV;
        }
        if (cityD < ans) ans = cityD;

    }while(next_permutation(chicken.begin(), chicken.end()));
    printf("%d\n", ans);
    // cout << ans << "\n";
}