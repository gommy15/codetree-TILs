// 반복문을 많이 쓰지 않고 진행해보자 시초과가 나지 않도록!!!
#include <iostream>
#define MAX_NM 100
using namespace std;

int n, m, end_of_array, end_of_tmp;
int arr[MAX_NM];

int GetEndIdxOfExplosion(int start_idx, int cur_num) {
    int end_idx = start_idx+1;
    while(end_idx < end_of_array) {
        if(arr[end_idx] == cur_num) end_idx++;
        else break;
    }

    return end_idx-1;
}

void FillZero(int start_idx, int end_idx) {
    for(int i=start_idx; i<=end_idx; i++) {
        arr[i] = 0;
    }
}

void Move() {
    int tmp[MAX_NM] = {};
    int end_of_tmp = 0;

    for(int i=0; i<end_of_array; i++) {
        if(arr[i] != 0) {
            tmp[end_of_tmp++] = arr[i];
        }
    }

    end_of_array = end_of_tmp;

    for(int i=0; i<end_of_array; i++) {
        arr[i] = tmp[i];
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    end_of_array = n;

    bool did_explode;
    do {
        did_explode = false;
        for(int cur_idx = 0; cur_idx<end_of_array; cur_idx++) {
            // 각 위치마다 그 뒤로 폭탄이 m개 있는지 확인

            // 이미 터지기로 예정되어 있는 폭탄은 패스
            if(arr[cur_idx] == 0) continue;

            // cur_idx로부터 연속하여 같은 숫자를 갖는 폭탄 중 가장 마지막 위치 탐색
            int end_idx = GetEndIdxOfExplosion(cur_idx, arr[cur_idx]);

            // 연속한 숫자의 개수가 m개 이상인 경우
            if(end_idx - cur_idx + 1 >= m) {
                // 폭탄 터짐
                FillZero(cur_idx, end_idx);
                did_explode = true;
            }
            
        }

        Move();
    } while (did_explode);

    cout << end_of_array << '\n';

    for(int i=0; i<end_of_array; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}