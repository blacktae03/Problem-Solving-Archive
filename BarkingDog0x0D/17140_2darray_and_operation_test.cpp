#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> v;

    v.push_back({4,2});
    v.push_back({3,2});
    v.push_back({1,3});
    v.push_back({2,2});

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first < b.first;
        else return a.second < b.second;
    });

    for (auto p : v) {
        cout << p.first << ' ' << p.second << '\n';
    }
}