#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int sum = 0;
            for(int k=i; k<=j; k++) {
                sum += arr[k];
            }
            //안전하게 완탐으로 같은 값이 있는지 찾자
            double avg = (double)sum/(j-i+1);
            bool exist = false;
            for(int k=i; k<=j; k++) {
                if(arr[k] == avg) exist = true;
            }
            
            if(exist) cnt++;
        }
    }

    cout << cnt;
    return 0;
}