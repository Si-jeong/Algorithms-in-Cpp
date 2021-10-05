#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<int> arr;

    scanf("%d", &n);
    for(int i=0; i<2*n; i++){
        int t;
        scanf("%d", &t);
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());
    int minV = INT_MAX;
    for(int i=0; i<n; i++){
        int sum = arr[i] + arr[2*n-i-1];
        minV = min(minV, sum);
    }
    
    printf("%d\n", minV);
}