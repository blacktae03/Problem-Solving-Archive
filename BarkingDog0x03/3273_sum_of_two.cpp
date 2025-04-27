#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, tmp, x, cnt = 0;
    int arr[2000001] = {0,};

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        arr[tmp]++;
    }

    cin >> x;

    for(int j = 1; j <= (x-1)/2; j++)
        if(arr[j] == 1 && arr[x-j] == 1) cnt++;

    cout << cnt;
}