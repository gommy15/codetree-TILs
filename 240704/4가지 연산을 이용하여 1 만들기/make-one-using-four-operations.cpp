#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 1000000
#define OPERATOR_NUM 4

enum OPERATOR {
    SUBTRACT,
    ADD,
    DIV2,
    DIV3
};

int n;
int step[MAX_N*2];
bool visited[MAX_N*2];
queue<int> q;

int ans;

void Push(int num, int new_step) {
    q.push(num);
    visited[num] = 1;
    step[num] = new_step;
}

bool Possible(int num, int op) {
    if(op == SUBTRACT || op == ADD)
        return true;
    else if(op == DIV2)
        return num % 2 == 0;
    else
        return num % 3 == 0;
}

int Calculate(int num, int op) {
    if(op == SUBTRACT)
        return num-1;
    else if (op == ADD)
        return num+1;
    else if (op == DIV2)
        return num/2;
    else
        return num/3;
}

bool InRange(int num) {
    return 1<= num && num <= 2*n-1;
}

bool CanGo(int num) {
    return InRange(num) && !visited[num];
}

void BFS() {
    while(!q.empty()) {
        int curr_num = q.front();
        q.pop();

        for(int i=0; i<OPERATOR_NUM; i++) {
            if(!Possible(curr_num, i)) continue;

            int new_num = Calculate(curr_num, i);

            if(CanGo(new_num))
                Push(new_num, step[curr_num]+1);
        }

    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    Push(n, 0);
    BFS();

    cout << step[1];
    return 0;
}