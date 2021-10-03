#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist){
    int wSize = weak.size();
    for (int i=0; i<wSize; i++){
        weak.push_back(weak[i]+n);
    }

    int minV = 9; // 최소 친구 수
    for (int i=0; i<wSize; i++){ // 시작 위치 선택
        do{
            int idx = 0; // 친구
            int end = weak[i] + dist[idx]; // 이동 후 위치
            // 시작 위치에서 weak 지점 돌면서 체크
            for (int j=i; j<i+wSize; j++){
                if (end < weak[j]) { // 체크 하지 못한 weak 지점부터 친구 추가
                    idx++;
                    // 친구 더이상 없는 경우 끝내기
                    if (idx >= dist.size()) {
                        break;
                    }
                    end = weak[j] + dist[idx];
                }
            }
            minV = min(minV, idx+1);
        } while(next_permutation(dist.begin(), dist.end())); // 친구 선택
    }

    if (minV > dist.size()){
        return -1;
    }
    
    return minV;
}

int main(){
    int n=12;
    vector<int> weak = {1, 5, 6, 10};
    vector<int> dist = {1, 2, 3, 4};

    printf("%d\n", solution(n, weak, dist));
    return 0;
}