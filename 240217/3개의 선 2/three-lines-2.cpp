#include <iostream>
using namespace std;
#define MAX_N 20
#define MAX_XY 10

int n;
int x[MAX_N], y[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x[i]>>y[i];
    }

    int ans = 0;
    // 3개 직선 좌표 정하기
    for(int i=0; i<=MAX_XY; i++) {
        for(int j=0; j<=MAX_XY; j++) {
            for(int k=0; k<=MAX_XY; k++){
                // 3개의 직선이 x축과 평행할 때
                bool match = true;

                for(int l=0; l<n; l++) {
                    if(x[l] == i || x[l] == j || x[l] == k) continue;
                    match = false;
                }

                if(match) ans = 1;

                // 2개의 직선이 x축과 평행하고 1개의 직선이 y축과 평행할 때
                match = true;
                for(int l=0; l<n; l++) {
                    if(x[l] == i || x[l] == j || y[l] == k) continue;
                    match = false;
                }

                if(match) ans = 1;

                // 1개의 직선이 x축과 평행하고 2개의 직선이 y축과 평행할 때
                match = true;
                for(int l=0; l<n; l++) {
                    if(x[l] == i || y[l] == j || y[l] == k) continue;
                    match = false;
                }

                if(match) ans = 1;

                // 3개의 직선이 y축과 평행할 때
                match = true;
                for(int l=0; l<n; l++) {
                    if(y[l] == i || y[l] == j || y[l] == k) continue;
                    match = false;
                }

                if(match) ans = 1;
            }
        }
    }

    cout << ans;
    return 0;
}