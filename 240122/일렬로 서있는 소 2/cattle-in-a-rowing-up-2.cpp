#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100

int height[MAX_N];
int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> height[i];
    }

    int cnt = 0;
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            if(height[i] <= height[j]) {
                for(int k = j+1; k<n; k++) {
                    if(height[j] <= height[k]) cnt++;
                }
            }
        }
    }

    cout << cnt;
    return 0;
}