#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;
unordered_map<string, int> s_arr;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    int max_cnt = 0;

    while(n--) {
        string str;
        cin >> str;

        s_arr[str]++;

        max_cnt = max(max_cnt, s_arr[str]);
    }

    cout << max_cnt;
    return 0;
}