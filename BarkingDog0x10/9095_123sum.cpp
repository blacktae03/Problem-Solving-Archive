#include <bits/stdc++.h>
using namespace std;

int D[14];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    for (int i = 4; i <= 10; i++) D[i] = D[i-3] + D[i-2] + D[i-1];

    int T; cin >> T;

    while(T--) {
        int tmp; cin >> tmp;
        cout << D[tmp] << '\n';
    }

}

// 1을 만드는 경우의 수는 1
// 2를 만드는 경우의 수는 1을 만드는 경우의 수(+1 해주면 됨.) + 1
// 3을 만드는 경우의 수는 2를 만드는 경우의 수(+1 해주면 됨.) + 1을 만드는 경우의 수 (+2 해주면 되니까)
// n이 4 이상이면 D(n-3) + D(n-2) + D(n-1)임.