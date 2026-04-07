#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1, v2;

    for (int i = 0; i < 4; i++) v1.push_back(i);
    for (int i = 0; i < 5; i++) v2.push_back(i);

    for (int i = 0; i < v1.size()/2; i++) swap(v1[i], v1[v1.size()-i-1]);
    for (int i = 0; i < v1.size()/2; i++) swap(v2[i], v2[v2.size()-i-1]);

    for (auto i : v1) cout << i << ' ';
    cout << '\n';
    for (auto i : v2) cout << i << ' ';
    cout << '\n';

    for (int i = 0; i < 2; i++) {
        vector<int> v3;
        if (i == 0) {
            v3.push_back(1);
            v3.push_back(2);
            v3.push_back(3);
        }
        cout << v3.size();
    }
}
