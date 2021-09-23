#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int main(){
    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    sort(arr.begin(), arr.end());

    int i = 0;
    int result = 0;

    while (i<n) {
        int needs = arr[i];

        if (i+(needs-1) >= n){
            break;
        }
        if (arr[i+(needs-1)] > needs){
            arr[i+(needs-1)] -= (needs-1);
            i += needs-1;
        } else{
            result++;
            i += needs;
        }
    }

    cout << result << endl;


}