#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    long long total = 0; // 전체 음식을 먹는 시간
    for (int i=0; i<food_times.size(); i++){
        total += food_times[i];
    }
    if (total <= k) return -1;

    // 우선 순위 큐 (default 최대 힙 -> 최소 힙 구현)
    priority_queue<pair<int, int> > pq;

    for (int i=0; i<food_times.size(); i++){
        pq.push({-food_times[i], i+1}); // -음식섭취시간, 번호
    }

    total = 0; // 먹기 위해 사용한 시간
    long long prev = 0; // 직전에 다 먹은 시간
    long long count = food_times.size(); // 남은 음식의 개수

    while(true){
        if (total + ((-pq.top().first - prev) * count) > k){
            break;
        }

        int now = -pq.top().first;
        pq.pop();
        total += (now-prev) * count;
        count -= 1;
        prev = now;
    }

    vector<pair<int, int> > result;
    while(!pq.empty()){
        int food_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        result.push_back({food_time, num});
    }

    sort(result.begin(), result.end(), compare); //음식의 번호 기준으로 정렬
    return result[(k-total) % count].second;
}

int main(){

    vector<int> food_times;

    food_times.push_back(3);
    food_times.push_back(1);
    food_times.push_back(2);

    long long k = 5;
    
    printf("%d\n", solution(food_times, k));
    
    // cout << solution(food_times, k) << '\n';


}