#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX_N 10

int n;
int cost[MAX_N][MAX_N];
bool visited[MAX_N];
vector<int> picked;

int ans = INT_MAX;

void FindMin(int cnt) {
    if(cnt == n) {
        int total_cost = 0;
        for(int i=0; i<(int)picked.size()-1; i++) {
            int curr_cost = cost[picked[i]][picked[i+1]];
            if(curr_cost == 0) return;

            total_cost += curr_cost;
        }

        int additional_cost = cost[picked.back()][0];
        if(additional_cost == 0) return;

        ans = min(ans, total_cost+additional_cost);
        return;
    }

    for(int i=0; i<n; i++) {
        if(visited[i]) continue;
        
        visited[i] = true;
        picked.push_back(i);

        FindMin(cnt+1);

        visited[i] = false;
        picked.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> cost[i][j];
        }
    }

    visited[0] = true;
    picked.push_back(0);
    FindMin(1);

    cout << ans;

    return 0;
}