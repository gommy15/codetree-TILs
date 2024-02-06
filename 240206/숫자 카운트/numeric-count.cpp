#include <iostream>
using namespace std;
#define MAX_N 10

int n;
int b_num[MAX_N], cnt_one[MAX_N], cnt_two[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> b_num[i] >> cnt_one[i] >> cnt_two[i];
    }

    int cnt = 0;
    for(int i=1; i<10; i++) {
        for(int j=1; j<10; j++) {
            if(i == j) continue;
            for(int k=1; k<10; k++) {
                if(k == i || k == j) continue;
                
                bool right_num = true;
                for(int l=0; l<n; l++) {
                    int num1 = b_num[l]/100, num2 = (b_num[l]%100)/10, num3 = b_num[l]%10;
                    int o_cnt = 0, t_cnt = 0;

                    if(i == num1) o_cnt++;
                    if(j == num2) o_cnt++;
                    if(k == num3) o_cnt++;

                    if(i == num2 || i == num3) t_cnt++;
                    if(j == num1 || j == num3) t_cnt++;
                    if(k == num1 || k == num2) t_cnt++;

                    if(cnt_one[l] != o_cnt || cnt_two[l] != t_cnt){
                        right_num = false;
                        break;
                    }
                }

                if(right_num) cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}