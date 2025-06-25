#include <bits/stdc++.h>
using namespace std;

int n;
int nums[100002], D[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    D[1] = nums[1];

    for (int i = 2; i <= n; i++) {
        D[i] = max(D[i-1] + nums[i], nums[i]);
    }

    cout << *max_element(D+1, D+n+1);
}

// 와 v4까지 만들면서 드디어 깨달았다.
// D[i] = i번째 수까지의 연속합의 최댓값 (i번째 수는 무조건 들어가야함)
// D[N] = max(D[N-1] + nums[N], nums[N])