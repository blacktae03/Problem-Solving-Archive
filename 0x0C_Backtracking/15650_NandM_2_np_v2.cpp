#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[n] = {0,};
    fill(arr, arr+m, 1);

    do {
        for (int i = 1; i <= n; i++)
            if (arr[i-1]) cout << i << ' ';
        cout << '\n';
    } while (prev_permutation(arr, arr+n));
}