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
        cin>>spot[i][0] >> spot[i][1];
    }

    int min_area = INT_MAX;

    for(int i=0; i<n; i++){
        int x_min = INT_MAX, y_min = INT_MAX;
        int x_max = INT_MIN, y_max = INT_MIN;

        for(int j=0; j<n; j++){
            if(i==j) continue;
            x_min = min(x_min, spot[j][0]);
            x_max = max(x_max, spot[j][0]);
            y_min = min(y_min, spot[j][1]);
            y_max = max(y_max, spot[j][1]);
        }

        int area = (x_max-x_min) * (y_max-y_min);
        min_area = min(min_area, area);
    }

    cout << min_area;
    return 0;
}