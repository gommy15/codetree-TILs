#include <iostream>
#include <algorithm>
using namespace std;
#define OFFSET 1000

int x1, x2, y1, y2;
int arr[OFFSET*2+1][OFFSET*2+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> x1>>y1>>x2>>y2;

    x1+=OFFSET;
    x2+=OFFSET;
    y1+=OFFSET;
    y2+=OFFSET;
    
    for(int i=x1; i<x2; i++) {
        for(int j=y1; j<y2; j++) {
            arr[i][j] = 1;
        }
    }

    cin >> x1>>y1>>x2>>y2;

    x1+=OFFSET;
    x2+=OFFSET;
    y1+=OFFSET;
    y2+=OFFSET;
    
    for(int i=x1; i<x2; i++) {
        for(int j=y1; j<y2; j++) {
            arr[i][j] = 2;
        }
    }
    x1=OFFSET*2+1;
    y1=OFFSET*2+1;
    x2=0;
    y2=0;
    bool exist = false;
    for(int i=0; i<OFFSET*2+1; i++) {
        for(int j=0; j<OFFSET*2+1; j++) {
            if(arr[i][j] == 1) {
                exist = true;
                x1 = min(x1, i);
                y1 = min(y1, j);
                x2 = max(x2, i);
                y2 = max(y2, j);
            }
        }
    }

    if(exist) cout << (x2-x1+1)*(y2-y1+1);
    else cout << 0;
    return 0;
}


// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define OFFSET 1000
// #define N   2

// int x1[N], x2[N], y1[N], y2[N];
// int arr[OFFSET*2+1][OFFSET*2+1];

// int main() {
//     // 여기에 코드를 작성해주세요.
//     for(int i=0; i<N; i++) {
//         cin >> x1[i] >> y1[i]>>x2[i]>>y2[i];
//         x1[i] += OFFSET;
//         x2[i] += OFFSET;
//         y1[i] += OFFSET;
//         y2[i] += OFFSET;

//         for(int j=x1[i]; j<x2[i]; j++) {
//             for(int k=y1[i]; k<y2[i]; k++) {
//                 arr[j][k] = i+1;
//             }
//         }
//     }

//     int min_x = OFFSET*2, max_x = 0, min_y = OFFSET*2, max_y = 0;
//     bool exist = false;
//     for(int i = 0; i <= OFFSET*2; i++)
//         for(int j = 0; j <= OFFSET*2; j++)
//             if(arr[i][j] == 1) {
//                 exist = true;
//                 min_x = min(min_x, i);
//                 max_x = max(max_x, i);
//                 min_y = min(min_y, j);
//                 max_y = max(max_y, j);
//             }

//     if(exist) cout << (max_x-min_x+1) * (max_y-min_y+1);
//     else cout << 0;
// }