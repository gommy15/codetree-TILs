#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100
#define MAX_AB 1000

int n;
int a[MAX_N+1], b[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }

    int max_tm = 0;
    for(int i=0; i<n; i++) {
        int tm = 0;
        int timeline[MAX_AB+1] = {};
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            
            for(int k=a[j]; k<b[j]; k++) {
                timeline[k] = 1;
            }
        }

        for(int k=0; k<=MAX_AB; k++){
            if(timeline[k] == 1) tm++;
        }
        max_tm = max(max_tm, tm);
    }

    cout << max_tm;
    return 0;
}