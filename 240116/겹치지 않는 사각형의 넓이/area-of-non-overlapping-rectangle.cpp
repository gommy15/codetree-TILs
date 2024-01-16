#include <iostream>
#include <algorithm>
using namespace std;
#define OFFSET 1000

int x1, x2, y1, y2;
int arr[OFFSET*2+1][OFFSET*2+1];

int main() {
    // 여기에 코드를 작성해주세요.
    int min_x1 = OFFSET*2, max_x2 = 0, min_y1 = OFFSET*2, max_y2 = 0;
    for(int i=0; i<2; i++) {
        cin >>x1>>y1>>x2>>y2;

        x1+=OFFSET;
        x2+=OFFSET;
        y1+=OFFSET;
        y2+=OFFSET;

        min_x1 = min(min_x1, x1);
        max_x2 = max(max_x2, x2);
        min_y1 = min(min_y1, y1);
        max_y2 = max(max_y2, y2);

        for(int j=x1; j<x2; j++) {
            for(int k=y1; k<y2; k++) {
                arr[j][k] = 1;
            }
        }
    }

    cin >> x1>>y1>>x2>>y2;
    x1+=OFFSET;
    x2+=OFFSET;
    y1+=OFFSET;
    y2+=OFFSET;

    min_x1 = min(min_x1, x1);
    max_x2 = max(max_x2, x2);
    min_y1 = min(min_y1, y1);
    max_y2 = max(max_y2, y2);

    for(int i=x1; i<x2; i++) {
        for(int j=y1; j<y2; j++) {
            arr[i][j] = 0;
        }
    }

    int cnt=0;

    for(int i=min_x1; i<max_x2; i++) {
        for(int j=min_y1; j<max_y2; j++) {
            if(arr[i][j] == 1) cnt++;
        }
    }

    cout << cnt;
    return 0;
}