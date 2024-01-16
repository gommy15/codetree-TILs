#include <iostream>
using namespace std;
#define MAX_R 200000
#define OFFSET 100000

int arr[MAX_R+1];
int n, x;
char dir;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    
    int now = OFFSET;
    for(int i=0; i<n; i++) {
        cin >> x>>dir;

        if(dir == 'L') {
            while(x--) {
                arr[now] = 1;
                if(x) now--;
            }
        } else if (dir == 'R') {
            while(x--) {
                arr[now] = 2;
                if(x) now++;
            }
        }
        

        // if(dir == 'L') {
        //     for(int j=now; j>now-x; j--) {
        //         arr[j] = 1;
        //     }
        //     now -= (x-1);
        // } else if (dir == 'R') {
        //     for(int j=now; j<now+x; j++) {
        //         arr[j] = 2;
        //     }
        //     now += (x-1);
        // }

    }

    int w=0, b=0;
    for(int i=0; i<MAX_R+1; i++) {
        if(arr[i] == 1) w++;
        else if (arr[i] == 2) b++;
    }

    cout << w << ' ' << b;

    return 0;
}