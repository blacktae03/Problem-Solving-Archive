#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1, v2;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    cout << v1.size();

    v2.push_back(4);
    v2.push_back(5);

    v1 = v2;
    for (auto i : v1) cout << i << ' ';
    cout << '\n' << v1.size();
}