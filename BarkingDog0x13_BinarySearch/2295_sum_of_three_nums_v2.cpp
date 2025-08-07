#include <bits/stdc++.h>
using namespace std;

int N;
long ans;
int U[1004];
bool C[1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fill(C+3, C+1004, 1);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> U[i];
    sort(U, U+N);

    do {
        int sum = 0;
        for (int i = 0; i < N; i++) sum += C[i] ? 0 : U[i]; // N 이거만 없애도 될 거 같은데 흠..
        if (!binary_search(U, U+N, sum)) continue; // lgN
        ans = max((lower_bound(U, U+N, sum) - U), ans); // lgN
    } while(next_permutation(C, C+N)); // N^3

    cout << U[ans];
}
// O(N^4)라서 시간초과 뜸 ㅠㅠ