#include <bits/stdc++.h>
using namespace std;

int N, goal, mini = INT_MAX;
int pre;
pair<int, int> ans;
int S[100010];

bool solve(int i, int mid) {
    return S[i] + S[mid] >= 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> S[i];
    sort(S, S+N); // NlgN

    for (int i = 0; i < N-1; i++) {
        // for (int j = i+1; j < N; j++) { // N^2
        //     int tmp = abs(S[i] + S[j]);
        //     if (tmp < mini) {
        //         mini = tmp;
        //         ans = {S[i], S[j]};
        //     }
        // }

        // goal = S[i] * -1;
        int st = i+1, en = N-1;
        int mid = (st+en)/2;
        pre = abs(S[i] + S[mid]);

        while (st < en) {
            if (solve(i, mid)) en = mid;
            else st = mid+1;
            mid = (st+en)/2;
            pre = abs(S[i] + S[mid]);
        }

        int tmp = mid;
        if (abs(S[mid]) > abs(S[i]) && abs(S[i] + S[mid]) > abs(S[i] + S[mid-1]) && mid-1 > i) tmp = mid-1;
        // else if (abs(S[mid]) < abs(S[i]) && abs(S[i] + S[mid]) > abs(S[i] + S[mid+1]) && mid+1 < N) tmp = mid+1;
        mid = tmp;

        if (abs(S[i] + S[mid]) < mini) {
            mini = abs(S[i] + S[mid]);
            ans = {S[i], S[mid]};
        }
    }

    cout << ans.first << ' ' << ans.second;
}
// 6
// -99 -6 -5 2 98 101
// -99 98 나오게 하기.