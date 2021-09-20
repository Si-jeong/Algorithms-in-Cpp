#include <iostream>
#include <vector>
using namespace std;

int n, m, result;


int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        int min_value = 10001;
        for(int j=0; j<m; j++){
            int x;
            cin >> x;
            min_value = min(min_value, x);
        }
        result = max(min_value, result);
    }

    cout << result << endl;
}