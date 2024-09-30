#include <iostream>
#include <string>
using namespace std;
#define MAX_N 200

string arr[MAX_N];
int cnt = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    while(true) {
        string str;
        cin >> str;
        if(str == "0") break;

        arr[cnt] = str;
        cnt++;
    }

    cout << cnt << '\n';

    for(int i=1; i<cnt+1; i=i+2){
        cout << arr[i] << '\n';
    }
    return 0;
}