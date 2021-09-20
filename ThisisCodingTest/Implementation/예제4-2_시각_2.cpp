#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    char find_char = n+'0';
    int count = 0;

    for(int i=0; i<60; i++){
        for(int j=0; j<60; j++){
            string s1 = to_string(i);
            string s2 = to_string(j);
            if ((s1.find(find_char) != string::npos) || (s2.find(find_char) != string::npos)){
                count++;
            }
        }
    }
    count = count * n + 60 * 60;
    cout << count << "\n";


}