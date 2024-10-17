#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 1000

int n, m;
vector<int> graph[MAX_N+1];
bool visited[MAX_N+1];
int cnt = 0;

void Dfs(int vertex) {
    for(int i=0; i<graph[vertex].size(); i++) {
        int cur_v = graph[vertex][i];
        if(!visited[cur_v]) {
            visited[cur_v] = 1;
            cnt++;
            Dfs(cur_v);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    int x, y;
    for(int i=0; i<m; i++) {
        cin >> x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    visited[1] = 1;
    Dfs(1);

    cout << cnt;

    return 0;
}