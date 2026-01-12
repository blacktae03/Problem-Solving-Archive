// 정답인 거 같은데 백준 서버 먹통 250625
#include <bits/stdc++.h>
using namespace std;

int N;
int nums[1004], D[1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
    }

    D[1] = 1;

    for (int i = 2; i <= N; i++) {
        D[i] = 1;

        for (int j = i-1; j >= 1; j--) {
            if (nums[i] > nums[j]) {
                D[i] = max(D[i], D[j]+1);
            }
        }
    }

    cout << *max_element(D+1, D+N+1);
}
// D[i] = i번째 수가 마지막 수로 포함된 부분증가수열의 길이의 최댓값