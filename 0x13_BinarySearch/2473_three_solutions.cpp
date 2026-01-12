#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll mini = LLONG_MAX;
ll A[5005];
pair<pair<ll, ll>, ll> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    for (int i = 0; i < N-2; i++) {
        ll tmp = A[i];
        for (int j = i+1; j < N-1; j++) {
            tmp += A[j];

            int st = j+1, en = N-1;
            int mid = (st+en)/2;

            while(st < en) {
                if(A[mid] < tmp*-1) st = mid+1;
                else en = mid;
                mid = (st+en)/2;
            }

            if (abs(tmp + A[mid]) > abs(tmp + A[mid-1]) && mid-1 > j) mid = mid-1;
            
            if (abs(tmp + A[mid]) < mini) {
                mini = abs(tmp + A[mid]);
                ans = {{A[i], A[j]}, A[mid]};
            }

            tmp -= A[j];
        }
    }
    
    cout << ans.first.first << ' ' << ans.first.second << ' ' << ans.second;
}