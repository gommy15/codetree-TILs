#include <iostream>
#include <utility>
using namespace std;
#define MAX_M 100
#define MAX_N 26

int n, m, p;
char c[MAX_M];
int u[MAX_M];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>p;
    
    for(int i=0; i<m; i++) {
        cin >> c[i]>>u[i];
    }

    // 모두 읽은 채팅이라면 읽지 않은 사람 없음
    if(u[p-1] == 0) return 0;

    // 각 사람에 대해 채팅을 읽었는지 확인
    for(int i=0; i<n; i++) {
        char member = 'A' + i;
        bool read = false;

        for(int j=0; j<m; j++) {
            // p번 메시지를 읽은 사람 수와 같거나 많은 채팅을 기준으로 단 한번이라도 채팅을 쳤다면 확실히 채팅을 읽음
            if(u[j] >= u[p-1] && c[j] == member) read = true;
        }

        if(read == false)
            cout << member << ' ';
    }

    
    
    return 0;
}