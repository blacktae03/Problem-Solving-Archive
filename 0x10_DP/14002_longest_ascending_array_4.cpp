#include <bits/stdc++.h>
using namespace std;

int N;
int A[1004], D[1004][4];
vector<int> M[1004][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for (int i = 1; i <= N; i++) cin >> A[i];
    D[1][0] = 0;
    D[1][1] = 1;
    M[1][1].push_back(1);
    
    for (int i = 2; i <= N; i++) {
        if (D[i-1][0] > D[i-1][1]) {
            D[i][0] = D[i-1][0];
            M[i][0] = M[i-1][0];
        }
        else {
            D[i][0] = D[i-1][1];
            M[i][0] = M[i-1][1];
        }

        D[i][1] = 1;
        M[i][1].push_back(i);

        for (int j = 1; j <= i-1; j++) {
            if (A[i] <= A[j]) continue;
            else if (D[j][1]+1 > D[i][1]) {
                D[i][1] = D[j][1]+1;
                M[i][1] = M[j][1];
                M[i][1].push_back(i);
            }
        }
    }
    
    if (D[N][0] > D[N][1]) {
        cout << D[N][0] << '\n';
        for (auto i : M[N][0]) cout << A[i] << ' ';
    }

    else {
        cout << D[N][1] << '\n';
        for (auto i : M[N][1]) cout << A[i] << ' ';
    }
}
// D[i][0or1] = i번쨰 수를 포함한(1) 또는 포함하지 않은(0) 증가하는 부분수열의 길이의 최댓값