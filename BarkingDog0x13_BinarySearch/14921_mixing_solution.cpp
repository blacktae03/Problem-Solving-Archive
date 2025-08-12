#include <bits/stdc++.h>
using namespace std;

int N, ans = INT_MAX;
int A[100010];

bool solve(int target, int mid) {
    return A[mid] < target;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    // sort(A, A+N);

    for (int i = 0; i < N-1; i++) {
        int st = i+1, en = N-1;
        int mid = (st+en)/2;

        while(st < en) {
            if (solve(A[i]*-1, mid)) st = mid+1;
            else en = mid;
            mid = (st+en)/2;
        }

        if (abs(A[mid] + A[i]) > abs(A[mid-1] + A[i]) && mid-1 > i) mid = mid-1; 
        if (abs(A[mid] + A[i]) < abs(ans)) {
            // cout << i << ' ' << mid << '\n';
            ans = A[mid] + A[i];
        }
    }
    
    cout << ans;
}