#include <bits/stdc++.h>
using namespace std;

int N;
long long ans;
int A[4004], B[4004], C[4004], D[4004];
vector<int> AB, CD;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back((C[i] + D[j])*-1);
        }
    }
    
    sort(CD.begin(), CD.end());

    for (auto sum : AB) {
        ans += upper_bound(CD.begin(), CD.end(), sum) - lower_bound(CD.begin(), CD.end(), sum);
    }

    cout << ans;
}