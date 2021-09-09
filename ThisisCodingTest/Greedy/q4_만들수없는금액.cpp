#include <iostream>
#include <vector>

using namespace std;

int n, result;
vector<int> arr;

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    // 만들 수 없는 금액
    // 체크할 값 : 1, 1 + arr[0], 1 + arr[0] + arr[1], ..., 1 + arr[0] + arr[1] + ... + arr[n-1]
    
    result = 1; 
    for (int i=0; i<n; i++){
        if (result < arr[i]){ 
            break;
        }
        result += arr[i]; 
    }

    cout << result << endl;

}