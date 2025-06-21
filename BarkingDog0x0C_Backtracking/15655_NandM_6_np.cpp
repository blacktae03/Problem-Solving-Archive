#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[n];
    int idx[n] = {0,};
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    fill(idx, idx+m, 1);

    do {
        for (int i = 0; i < n; i++)
            if (idx[i]) cout << arr[i] << ' ';
        
        cout << '\n';
    } while (prev_permutation(idx, idx+n));
}