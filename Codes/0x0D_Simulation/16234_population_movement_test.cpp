#include <bits/stdc++.h>
using namespace std;

int main() {
    // vector<int> v;
    // v.push_back(3);

    // for (auto n : v) {
    //     if (n == 3) {
    //         v.push_back(1);
    //         v.push_back(2);
    //     }
    //     cout << n;
    // } // 안되넹 ㅎㅎ
    // cout << '\n';
    // for (auto n : v) {
    //     cout << n << ' ';
    // }

    // int i = 0;
    // int a = i%2 ? 3 : 4;
    // cout << a;

    vector<int> v;
    // v.push_back({3,3});
    // v.push_back({5,5});
    // cout << v.size() << '\n';
    // v.clear();
    // v.push_back({4,4});
    // cout << v.size() << '\n';

    // int a = 30;
    // a /= 6;
    // cout << a;
    // cout << '\n';

    // int N = 4;

    // for (int i = 0; i < 2*N-1; i++) {
    //     // fill(vis[i], vis[i]+101, 0);

    //     for (int j = i%2 ? 0 : 1; j < 2*N-1; j+=2) {
    //         // brd[i][j] = 0;
    //         cout << i << ' ' << j << " / ";
    //     }
    //     cout << '\n';
    // }

    v.push_back(3);
    v.push_back(6);
    v.push_back(9);

    int tmp = 0;
    int arr[10] = {0,};

    for (auto i : v) tmp += i;
    tmp /= v.size();
    for (auto i : v) arr[i] = tmp;

    for (int i = 0; i < 10; i++) {
        cout << arr[i];
    }
}