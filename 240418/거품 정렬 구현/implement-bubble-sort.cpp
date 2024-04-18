#include <iostream>
#define MAX_N 100
using namespace std;

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    bool sorted;
    do {
        sorted=true;
        for(int i=0; i<n-1; i++){
            if (arr[i] > arr[i+1]) {
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                sorted = false;
            }
        }
    } while(!sorted);

    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
    return 0;
}