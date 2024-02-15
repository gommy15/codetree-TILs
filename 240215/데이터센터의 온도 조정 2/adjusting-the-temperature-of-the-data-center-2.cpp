#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N   1000

int n, c, g, h;
int Ta[MAX_N], Tb[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>c>>g>>h;

    int min_deg = INT_MAX, max_deg = INT_MIN;
    for(int i=0; i<n; i++) {
        cin >> Ta[i]>>Tb[i];
        min_deg = min(min_deg, Ta[i]);
        max_deg = max(max_deg, Tb[i]);
    }

    int max_work = INT_MIN;
    for(int i=min_deg-1; i<=max_deg+1; i++) {
        int work = 0;

        for(int j=0; j<n; j++) {
            if(i < Ta[j]) work += c;
            else if (Ta[j] <= i && i <= Tb[j]) work += g;
            else if (Tb[j] < i) work += h;
        }

        max_work = max(max_work, work);
    }

    cout << max_work;
    return 0;
}