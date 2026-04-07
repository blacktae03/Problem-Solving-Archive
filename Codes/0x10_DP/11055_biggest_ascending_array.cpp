#include <bits/stdc++.h>
using namespace std;

int N;
int nums[1004], D[1004][2], T[1004][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) cin >> nums[i];

    D[1][1] = nums[1];
    T[1][1] = nums[1];
    D[1][0] = 0;

    for (int i = 2; i <= N; i++) {
        if (nums[i] > T[i-1][1]) D[i][1] = max(D[i][1], D[i-1][1] + nums[i]);
        if (nums[i] > T[i-1][0]) D[i][1] = max(D[i][1], D[i-1][0] + nums[i]);
        if (nums[i] <= T[i-1][1] && nums[i] <= T[i-1][0]) D[i][1] = nums[i];
        D[i][0] = max(D[i-1][0], D[i-1][1]);

        T[i][0] = D[i-1][0] > D[i-1][1] ? T[i-1][0] : T[i-1][1];
        T[i][1] = nums[i];
    }
    
    for (int j = 0; j <= 1; j++) {
        for (int i = 1; i <= N; i++) {
            cout << D[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int j = 0; j <= 1; j++) {
        for (int i = 1; i <= N; i++) {
            cout << T[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    cout << max(D[N][0], D[N][1]);
}
// D[i][0] = i번째 수가 포함되지않은 증가하는 부분수열의 합의 최댓값.
// D[i][1] = i번째 수가 포함되는 ...
// 10
// 1 100 2 50 60 3 5 6 7 8 일 때