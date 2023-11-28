#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_NUM 1000

int c, g, h, n;
pair<int, int> data_t[MAX_NUM];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>c>>g>>h;

    int ta, tb;
    int min_ta = INT_MAX, max_tb = INT_MIN;
    for(int i=0; i<n; i++) {
        cin >> ta>>tb;
        data_t[i] = make_pair(ta, tb);
        min_ta = min(min_ta, ta);
        max_tb = max(max_tb, tb);
    }

    int max_work = INT_MIN;
    for(int i=min_ta; i<=max_tb; i++) {
        int sum = 0;
        for(int j=0; j<n; j++) {
            if(i < data_t[j].first) sum += c;
            else if(data_t[j].first <= i && i <= data_t[j].second) sum += g;
            else if(data_t[j].second < i) sum += h;
        }

        max_work = max(max_work, sum);
    }


    cout << max_work;
    return 0;
}