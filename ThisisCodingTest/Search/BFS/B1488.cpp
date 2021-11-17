#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int minV = 1e9;
int maxV = -1e9;
vector<int> num;
int op[4]; // +, -, *, %

int operate(int i, int cnt, int result){
    switch (i)
    {
    case 0:
        result += num[cnt+1];
        break;
    case 1:
        result -= num[cnt+1];
        break;
    case 2:
        result *= num[cnt+1];
        break;
    case 3:
        result /= num[cnt+1];
        break;
    default:
        break;
    }
    return result;
}


void dfs (int cnt, int result){
    if (cnt == n-1){
        minV = min(minV, result);
        maxV= max(maxV, result);
        return;
    }
    for (int i=0; i<4; i++){
        if (op[i]>0){
            op[i]--;
            dfs(cnt+1, operate(i, cnt, result));
            op[i]++;
        }
    }

}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i=0, t; i<n; i++){
        cin >> t;
        num.push_back(t);
    }

    for (int i=0; i<4; i++){
        cin >> op[i];
    }

    dfs(0, num[0]);

    cout << maxV << '\n' << minV << '\n';


    return 0;
}