#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 26

int n;
int arr[MAX_N];
int cnt = 0;

void ChangeAlpa(int x, int y) {
    int tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;

    cnt++;
}

int main() {
    // 여기에 코드를 작성해주세요.
    char ch;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> ch;
        arr[i] = ch - 'A';
    }

    for(int i=0; i<n; i++) {
        if(arr[i] == i) continue;
        for(int j=i+1; j<n; j++) {
            if(arr[j] == i) {
                int x = j;
                while(arr[i] != i) {
                    ChangeAlpa(x-1, x);
                    x--;
                }
                break;
            }
        }
        // for(int j=0; j<n; j++) {
        //     cout << (char)(arr[j] + 'A')<< ' ';
        // }
        // cout << '\n';
    }

    cout << cnt;
    return 0;
}