// 다시 풀기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<pair<int, int> > > graph(n+2, vector<pair<int, int> >(n+4, {0, 0})); // 2차원 vector 선언 및 초기화
    vector<vector<int> > answer;

    // for(int i=0; i<n+2; i++){
    //     for(int j=0; j<n+4; j++){
    //         cout << "[" << graph[i][j].first << ", " << graph[i][j].second << "] ";
    //     }
    //     cout << "\n";
    // }

    for (int i=0; i<build_frame.size(); i++){
            for(int i=0; i<n+2; i++){
                for(int j=0; j<n+4; j++){
                    cout << "[" << graph[i][j].first << ", " << graph[i][j].second << "] ";
                }
                cout << "\n";
            }

        vector<int> v = build_frame[i];

        int x = v[0]+1; int y = v[1]+2;
        
        // 보1, 기둥0
        if (v[2]==1 && v[3]==1){ // 보 설치
            // cout << x-1 << " " << y-2 << "\n";
            if ((graph[x-1][y].second==1 || graph[x-1][y+1].second==1) || (graph[x][y-1].first==1 && graph[x][y+1].first==1)){

                // cout << x-1 << " " << y-2 << "\n";
                
                graph[x][y].first = 1;
                // vector<int> t = {x-1, y-2, 1};
                vector<int> t;
                t.push_back(x-1);
                t.push_back(y-2);
                t.push_back(1);
                answer.push_back(t);
            }else{
                continue;
            }
        }
        else if (v[2]==1 && v[3]==0){ // 보 삭제
            // cout << x-1 << " " << y-2 << "\n";

            // 보 위에 기둥 있는 경우
            if (graph[x][y].second == 1 || graph[x][y+1].second == 1){
                continue;
            }
            // 양 옆이 보인 보가 있는 경우
            if ((graph[x][y+1].first==1 && graph[x][y+2].first==1) || (graph[x][y-1].first==1 && graph[x][y-2].first==1)){
                continue;
            }
            cout << x-1 << " " << y-2 << "\n";

            graph[x][y].first=0;
            // erase-remove idiom
            // vector<int> t = {x-1, y-2, 1};
            vector<int> t;
            t.push_back(x-1);
            t.push_back(y-2);
            t.push_back(1);
            answer.erase(std::remove(answer.begin(),answer.end(), t), answer.end());
        }
        else if (v[2]==0 && v[3]==1){ // 기둥 설치
            cout << x-1 << " " << y-2 << "\n";

            if (x==1 || graph[x-1][y].second==1 || graph[x][y-1].first==1 || graph[x][y].first==1){
                cout << x-1 << " " << y-2 << "\n";
                
                graph[x][y].second = 1;
                // vector<int> t = {x-1, y-2, 0};
                vector<int> t;
                t.push_back(x-1);
                t.push_back(y-2);
                t.push_back(0);
                answer.push_back(t);

            }
            else{
                continue;
            }
        }
        else if (v[2]==0 && v[3]==0) { // 기둥 삭제
            // cout << x-1 << " " << y-2 << "\n";
            // 기둥 위에 보가 기둥 위 에 없는 경우
            if ((graph[x+1][y].first==1 && graph[x][y+1].second==0) || (graph[x+1][y-1].first==1 && graph[x][y-1].second==0)){
                continue;
            }
            // 기둥 위에 기둥이 있고, 양쪽에 보가 없는 경우
            if (graph[x+1][y].second==1 && graph[x+1][y].first==0 && graph[x+1][y-1].first==0){
                continue;
            }
            cout << x-1 << " " << y-2 << "\n";

            graph[x][y].second=0;
            // vector<int> t = {x-1, y-2, 0};
            vector<int> t;
            t.push_back(x-1);
            t.push_back(y-2);
            t.push_back(0);
            answer.erase(std::remove(answer.begin(),answer.end(), t), answer.end());

        }

    }

    for(size_t i=0; i<answer.size(); i++){
        vector<int> u = answer[i];
        cout << "[" << u[0] << ", " << u[1] << ", " << u[2] << "]\n";
    }
    
    sort(answer.begin(), answer.end());

    return answer;
}


int main(){
    vector<vector<int> > build_frame = {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}};
    vector<vector<int> > answer = solution(5, build_frame);
    for(size_t i=0; i<answer.size(); i++){
        vector<int> u = answer[i];
        cout << "[" << u[0] << ", " << u[1] << ", " << u[2] << "]\n";
    }
}