#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char graph[6][6];
vector <pair<int, int> > teachers;
vector <pair<int, int> > spaces;
bool ok = false;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool check(){
    for(int i=0; i<teachers.size(); i++){
        int x = teachers[i].first;
        int y = teachers[i].second;
        for (int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            while(!(nx<0 || nx>=n || ny<0 || ny>=n)){
                if(graph[nx][ny]=='S') return false;
                if(graph[nx][ny]=='O') break;
                nx += dx[k];
                ny += dy[k];
            }
        }
    }        
    return true;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> graph[i][j];
            if (graph[i][j]=='T'){
                teachers.push_back({i, j});
            }
            if (graph[i][j]=='X'){
                spaces.push_back({i, j});
            }
        }
    }

    vector<bool> binary(spaces.size());
    fill(binary.end()-3, binary.end(), true);

    do{
        for(int i=0; i<spaces.size(); i++){
            if (binary[i]){
                int x = spaces[i].first;
                int y = spaces[i].second;
                graph[x][y] = 'O';
            }
        }

        ok = check();
        if (ok){
            cout << "YES\n";
            break;
        }

        for(int i=0; i<spaces.size(); i++){
            if (binary[i]){
                int x = spaces[i].first;
                int y = spaces[i].second;
                graph[x][y] = 'X';
            }
        }

    } while(next_permutation(binary.begin(), binary.end()));

    if (!ok) cout << "NO\n";

    return 0;

}