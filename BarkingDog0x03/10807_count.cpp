#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, num,cnt =0,v;

    cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> v;

    for (auto num : arr)
        if(v==num) cnt++;

    cout << cnt;
}