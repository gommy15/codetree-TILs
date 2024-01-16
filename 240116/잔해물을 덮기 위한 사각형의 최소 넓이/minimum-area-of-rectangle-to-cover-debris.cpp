#include <iostream>
#include <algorithm>
using namespace std;
#define OFFSET 1000
#define N   2

int x1[N], x2[N], y1[N], y2[N];
int arr[OFFSET*2+1][OFFSET*2+1];

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0; i<N; i++) {
        cin >> x1[i] >> y1[i]>>x2[i]>>y2[i];
        x1[i] += OFFSET;
        x2[i] += OFFSET;
        y1[i] += OFFSET;
        y2[i] += OFFSET;

        for(int j=x1[i]; j<x2[i]; j++) {
            for(int k=y1[i]; k<y2[i]; k++) {
                arr[j][k] = i+1;
            }
        }
    }

    int min_x = OFFSET*2, max_x = 0, min_y = OFFSET*2, max_y = 0;
    bool exist = false;
    for(int i = 0; i <= OFFSET*2; i++)
        for(int j = 0; j <= OFFSET*2; j++)
            if(arr[i][j] == 1) {
                exist = true;
                min_x = min(min_x, i);
                max_x = max(max_x, i);
                min_y = min(min_y, j);
                max_y = max(max_y, j);
            }

    if(exist) cout << (max_x-min_x+1) * (max_y-min_y+1);
    else cout << 0;
}