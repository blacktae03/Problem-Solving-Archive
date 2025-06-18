#include <bits/stdc++.h>
using namespace std;

int N;
int arr[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp]++;
    }

    for (int j = 1; j <= 10000; j++) {
        for (int i = 1; i <= arr[j]; i++) {
            cout << j << '\n';
        }
    }
}