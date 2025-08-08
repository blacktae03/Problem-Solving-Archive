#include <bits/stdc++.h>
using namespace std;

int N, sum, ans;
int U[1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // fill(C+3, C+1004, 1);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> U[i];
    sort(U, U+N);
    
    for (int i = 0; i < N; i++) {
        sum += U[i];
        for (int j = i; j < N; j++) {
            sum += U[j];
            for (int k = j; k < N; k++) {
                sum += U[k];
                // for (int i = 0; i < N; i++) sum += C[i] ? 0 : U[i]; // N 이거만 없애도 될 거 같은데 흠..
                if (binary_search(U, U+N, sum)) ans = max(sum, ans); // lgN

                sum -= U[k];
            }
            sum -= U[j];
        }
        sum -= U[i];
    }

    cout << ans;
}
// O(N^3lgN)라서 시간초과 뜸 ㅠㅠ