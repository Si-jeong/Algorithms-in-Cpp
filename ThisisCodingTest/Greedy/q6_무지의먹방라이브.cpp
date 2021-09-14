// 다시 풀어보기!!!

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
    long long summary = 0; // 전체 음식을 먹는 시간
    for (int i=0; i<food_times.size(); i++){
        summary += food_times[i];
    }
    if (summary <= k) return -1;

    // 우선 순위 큐 (default 최대 힙 -> 최소 힙 구현)
    priority_queue<pair<int, int> > pq;

    for (int i=0; i<food_times.size(); i++){
        pq.push(make_pair(-food_times[i], i+1)); // -음식섭취시간, 번호
    }

    summary = 0; // 먹기 위해 사용한 시간
    long long previous = 0; // 직전에 다 먹은 시간
    long long length = food_times.size(); // 남은 음식의 개수

    while(summary + ((-pq.top().first - previous) * length) <= k){
        int now = -pq.top().first;
        pq.pop();
        summary += (now-previous)*length;
        length -= 1;
        previous = now;
    }

    vector<pair<int, int> > result;
    while(!pq.empty()){
        int food_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        result.push_back(make_pair(food_time, num));
    }

    sort(result.begin(), result.end(), compare); //음식의 번호 기준으로 정렬
    return result[(k-summary) % length].second;
}

int main(){

    vector<int> food_times;

    food_times.push_back(3);
    food_times.push_back(1);
    food_times.push_back(2);

    long long k = 5;

    cout << solution(food_times, k) << endl;


}