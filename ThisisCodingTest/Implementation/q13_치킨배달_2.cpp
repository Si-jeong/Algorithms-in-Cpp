#include <vector>
#include <climits> // INT_MAX
#include <algorithm> // min, sort, prev_permutation, next_permutation
#include <cstdlib> // abs
#include <cstdio> // scanf, printf

using namespace std;

int main(){
    int n, m;
    vector<pair<int, int> > chicken, house;

    scanf("%d %d", &n, &m);

    for (int i=0; i<n; i++){
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
    }

    vector<bool> v (chicken.size()-m, false);
    v.insert(v.end(), m, true);

    int ans = INT_MAX;
    
    do{
        int cityD = 0;
        vector<pair<int, int> > chosen;

        for (int i=0; i<chicken.size(); i++){
            if(v[i]){
                chosen.push_back({chicken[i].first, chicken[i].second});
            }
        }

        for (int i=0; i<house.size(); i++){
            int d, minV = INT_MAX;
            int x = house[i].first, y = house[i].second;
            
            for (int j=0; j<m; j++){
                d = abs(x-chosen[j].first) + abs(y-chosen[j].second);
                // if (minV > d) minV = d;
                minV = min(minV, d);
            }
            cityD += minV;
        }
        // if (cityD < ans) ans = cityD;
        ans = min(ans, cityD);

    } while(next_permutation(v.begin(), v.end()));
    printf("%d\n", ans);
    return 0;
}