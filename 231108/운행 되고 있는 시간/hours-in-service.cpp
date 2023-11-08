#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_DEV 100
#define MAX_TIME 1000

int n;
int develop[MAX_DEV][2];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> develop[i][0] >> develop[i][1];
    }

    int max_work = INT_MIN;
    for(int i=0; i<n; i++) {
        int work[MAX_TIME] = {};
        int max_end = INT_MIN;
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            int start = develop[j][0];
            int end = develop[j][1];

            max_end = max(max_end, end);

            for(int k=start; k<end; k++) {
                work[k]++; 
            }
        }
        int cnt = 0;
        for(int k=0; k<max_end; k++) {
            if(work[k] != 0) cnt++;
        }
        max_work = max(max_work, cnt);
    }

    cout << max_work;
    return 0;
}