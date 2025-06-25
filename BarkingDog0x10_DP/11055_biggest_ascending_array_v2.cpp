#include <bits/stdc++.h>
using namespace std;

int N;
int nums[1004], D[1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> nums[i];

    D[1] = nums[1];
    
    for (int i = 2; i <= N; i++) {
        D[i] = nums[i];
        for (int j = i-1; j >= 1; j--) {
            if (nums[i] > nums[j]) {
                D[i] = max(D[i], D[j] + nums[i]);
            }
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << D[i] << ' ';
    // }
    // cout << '\n';

    cout << *max_element(D+1, D+1+N);
}

// N의 제한이 1000이라는 건 O(N^2)이어도 된다는 것
// D[i] = i번째 숫자가 마지막 수로 포함된 증가부분수열의 최댓값