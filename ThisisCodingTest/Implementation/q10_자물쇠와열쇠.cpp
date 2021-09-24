#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key[0].size();
    int n = lock[0].size();

    vector<vector<int> > spanned_key;
    for(int i=0; i<n-1; i++){
        vector<int> element(m+2*(n-1), 0);
        spanned_key.push_back(element);
    }
    for(int i=0; i<m; i++){
        vector<int> v(2*(n-1), 0);
        v.insert(v.begin() + n-1, key[i].begin(), key[i].end());
        spanned_key.push_back(v);
    }
    for(int i=0; i<n-1; i++){
        vector<int> element(m+2*(n-1), 0);
        spanned_key.push_back(element);
    }

    // for(int i=0; i<n+m-1; i++){
    //     for(int j=0; j<n+m-1; j++){
    //         cout << spanned_key[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i=0; i<n+m-1; i++){
        for(int j=0; j<n+m-1; j++){
            // cout << i << j << spanned_key[i][j] << "\n";

            vector<bool> unlocked(4, true);
            bool imp = false;

            for(int k=0; k<n; k++){
                if (imp){
                    break;
                }
                for(int z=0; z<n; z++){
                    // cout << "[" << k << "][" << z << "] ";
                    // cout << "[" << n-z-1 << "][" << k << "] ";
                    // cout << "[" << n-k-1 << "][" << n-z-1 << "] ";
                    // cout << "[" << z << "][" << n-k-1 << "] ";

                    if (find(unlocked.begin(), unlocked.end(), true) == unlocked.end()) {
                        imp = true;
                        break;

                    }
                    if (unlocked[0] && spanned_key[i+k][j+z] + lock[k][z] != 1){
                        unlocked[0] = false;
                    }
                    if (unlocked[1] && spanned_key[i+k][j+z] + lock[n-z-1][k] != 1){
                        unlocked[1] = false;
                    }
                    if (unlocked[2] && spanned_key[i+k][j+z] + lock[n-k-1][n-z-1] != 1){
                        unlocked[2] = false;
                    }
                    if (unlocked[3] && spanned_key[i+k][j+z] + lock[z][n-k-1] != 1){
                        unlocked[3] = false;
                    }
                }
                // cout << "\n";
            }

            // cout << "=====================\n";

            if (imp) continue;

            if (find(unlocked.begin(), unlocked.end(), true) != unlocked.end()){
                return true;
            }

        }
    }

    return false;
}

int main(){
    vector<vector<int> > key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int> > lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    if (solution(key, lock))
        cout << "true" << "\n";
    else
        cout << "false" << "\n";

}