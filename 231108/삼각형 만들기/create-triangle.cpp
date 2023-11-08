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

    int max_area = INT_MIN;
    bool possible = false;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            for(int k=0; k<n; k++){
                if(k==i || k==j) continue;
                if(spot[i][1] == spot[j][1] && spot[j][0] == spot[k][0]){
                    int area = abs(spot[i][0]-spot[j][0]) * abs(spot[j][1]-spot[k][1]);

                    max_area = max(max_area, area);
                    possible = true;
                }
            }
        }
    }

    if(possible) cout << max_area;
    else cout << 0;
    return 0;
}