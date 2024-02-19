#include <iostream>
#include <string>
using namespace std;
#define MAX_ARR 3
#define MAX_NUM 9

string inp[MAX_ARR];
int arr[MAX_ARR][MAX_ARR];

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0; i<MAX_ARR; i++) {
        cin >> inp[i];
    }

    for(int i=0; i<MAX_ARR; i++) {
        for(int j=0; j<MAX_ARR; j++) {
            arr[i][j] = inp[i][j]-'0';
        }
    }

    int cnt = 0;
    //모든 쌍 만들어 보기
    for(int i=1; i<=MAX_NUM; i++) {
        for(int j=i+1; j<=MAX_NUM; j++) {

            bool win = false;

            int num_i = 0, num_j = 0;

            // 가로로 팀이 이겼을 때
            for(int k=0; k<MAX_ARR; k++) {
                num_i = 0; num_j = 0;
                for(int l=0; l<MAX_ARR; l++) {
                    if(arr[k][l] == i) num_i++;
                    if(arr[k][l] == j) num_j++;
                }

                if(num_i+num_j == 3 && num_i>=1 && num_j>=1) win = true;
            } 
            
            // 세로로 팀이 이겼을 때
            for(int k=0; k<MAX_ARR; k++) {
                num_i = 0; num_j = 0;
                for(int l=0; l<MAX_ARR; l++) {
                    if(arr[l][k] == i) num_i++;
                    if(arr[l][k] == j) num_j++;
                }

                if(num_i+num_j == 3 && num_i>=1 && num_j>=1) win = true;
            }

            // 오른쪽 아래로 향하는 대각선으로 이겼을 때
            num_i = 0; num_j = 0;
            for(int k=0; k<MAX_ARR; k++) {
                if(arr[k][k] == i) num_i++;
                if(arr[k][k] == j) num_j++;

                if(num_i+num_j == 3 && num_i>=1 && num_j>=1) win = true;
            }

            // 왼쪽 아래로 향하는 대각선으로 이겼을 때
            num_i = 0; num_j = 0;
            for(int k=0; k<MAX_ARR; k++) {
                if(arr[k][MAX_ARR-1-k] == i) num_i++;
                if(arr[k][MAX_ARR-1-k] == j) num_j++;

                if(num_i+num_j == 3 && num_i>=1 && num_j>=1) win = true;
            }

            if(win) cnt++;
        }
    }

    cout << cnt;
    return 0;
}