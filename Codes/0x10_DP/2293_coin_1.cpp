#include <bits/stdc++.h>
using namespace std;

int n, k;
bool C[10004];
int D[10004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        C[tmp] = 1;
        D[tmp] = 1;
    }
    
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < i; j++) {
            if (!C[j]) continue;
            D[i] += 0;
        }
    }

    cout << D[k];
    
}
// D[i] = i원이 되도록 하는 경우의 수의 합