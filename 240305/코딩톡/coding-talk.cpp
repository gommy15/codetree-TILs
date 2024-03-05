#include <iostream>
#include <utility>
using namespace std;
#define MAX_M 100
#define MAX_N 26

int n, m, p;
char c[MAX_M];
int u[MAX_M];
int member[MAX_N];
// pair<char, int> message[MAX_M+1];

void FindMember() {
    if(u[p-1] == 0) {
        cout << ' ';
    } else {
        for(int i=p-1; i<m; i++) {
           member[(int)(c[i]-'A')] = 1;
        }   

        for(int i=0; i<n; i++) {
            if(member[i] == 0) {
                char mem = 'A'+i;
                cout << mem << ' ';
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>p;
    
    for(int i=0; i<m; i++) {
        cin >> c[i]>>u[i];
    }

    FindMember();
    
    return 0;
}