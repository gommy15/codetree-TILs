#include <iostream>
using namespace std;
#define MAX_N 1000

int n, m;
int ans;

int graph[MAX_N+1][MAX_N+1];
bool visited[MAX_N+1];

void DFS(int vertex) {
    for(int cur_v=1; cur_v<=n; cur_v++) {
        if(graph[vertex][cur_v] && !visited[cur_v]) {
            visited[cur_v] = true;
            ans++;
            DFS(cur_v);
        }
    }
}

int main() {
    cin >> n>>m;

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x>>y;
        
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    visited[1] = true;
    DFS(1);

    cout << ans;
}

// #include <iostream>
// #include <vector>
// using namespace std;
// #define MAX_N 1000

// int n, m;
// int vertex_cnt;

// vector<int> graph[MAX_N+1];
// bool visited[MAX_N+1];

// void DFS(int vertex) {
//     for(int i=0; i<(int)graph[vertex].size(); i++) {
//         int cur_v = graph[vertex][i];
//         if(!visited[cur_v]) {
//             visited[cur_v] = true;
//             vertex_cnt++;
//             DFS(cur_v);
//         }
//     }
// }

// int main() {
//     // 여기에 코드를 작성해주세요.

//     cin >> n>>m;

//     int v1, v2;
//     for(int i=0; i<m; i++) {
//         cin >> v1>>v2;
//         graph[v1].push_back(v2);
//         graph[v2].push_back(v1);
//     }

//     visited[1] = true;
//     DFS(1);

//     cout << vertex_cnt;
//     return 0;
// }