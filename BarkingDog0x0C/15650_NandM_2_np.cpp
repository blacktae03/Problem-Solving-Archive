#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[n];
    fill(arr, arr+n, 1);
    fill(arr, arr+m, 0);

    do {
        for (int i = 1; i <= n; i++)
            if (!arr[i-1]) cout << i << ' ';
        cout << '\n';
    } while (next_permutation(arr, arr+n));
}