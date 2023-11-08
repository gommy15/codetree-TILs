#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_SPOT 100

int n;
int spot[MAX_SPOT][2];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> spot[i][0] >> spot[i][1];
    }

    int min_dis = INT_MAX;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if (i==j) continue;

            int x1=spot[i][0], y1 = spot[i][1];
            int x2 = spot[j][0], y2 = spot[j][1];

            int distance = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            min_dis = min(min_dis, distance);
        }
    }

    cout << min_dis;
    return 0;
}