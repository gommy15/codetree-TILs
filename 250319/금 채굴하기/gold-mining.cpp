#include <bits/stdc++.h>
using namespace std;
#define MAX_N 20

int n, m;
int grid[MAX_N][MAX_N];

int GetGold(int x, int y, int k) {
    int num_g = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(abs(x-i)+ abs(y-j) <= k) {
                num_g += grid[i][j];
            }
        }
    }

    return num_g;
}

int GetArea(int k) {
    return k*k + (k+1)*(k+1);
}

int main() {
    cin >> n>>m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int max_g = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<=2*(n-1); k++) {
                int num_g = GetGold(i, j, k);

                if (num_g*m >= GetArea(k)) {
                    max_g = max(max_g, num_g);
                }
            }
        }
    }

    cout << max_g;
    return 0;
}