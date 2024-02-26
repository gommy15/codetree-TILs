#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX_N 10
#define MAX_M 100

int n, m;
pair<int, int> numbers[MAX_M];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a>>b;
        numbers[i] = make_pair(a, b);
    }

    int max_cnt = 0;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            int cnt = 0;
            for(int k=0; k<m; k++) {
                if((i == numbers[k].first && j == numbers[k].second) || (i==numbers[k].second && j==numbers[k].first))
                    cnt++;
            }
            max_cnt = max(max_cnt, cnt);
        }
    }

    cout << max_cnt;
    return 0;
}