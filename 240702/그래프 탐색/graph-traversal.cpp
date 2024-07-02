#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 1000

int n, m;
int vertex_cnt;

bool visited[MAX_N+1];
vector<int> graph[MAX_N+1];

void DFS(int vertex) {
    for(int i=0; i<graph[vertex].size(); i++) {
        int curr_v = graph[vertex][i];
        if(!visited[curr_v]) {
            visited[curr_v] = true;
            vertex_cnt++;
            DFS(curr_v);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n>>m;

    for(int i=0; i<m; i++) {
        int v1, v2;
        cin >> v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    visited[1] = true;
    DFS(1);

    cout << vertex_cnt;

    return 0;
}