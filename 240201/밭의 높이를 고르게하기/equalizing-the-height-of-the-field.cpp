#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100

int n, t, h;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>h>>t;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int min_cost = INT_MAX;
    for(int i=0; i<=n-t; i++) {
        int cost = 0;
        for(int j=i; j<i+t; j++) {
            cost += abs(arr[j]-h);
        }
        min_cost = min(min_cost, cost);
    }

    cout << min_cost;
    return 0;
}