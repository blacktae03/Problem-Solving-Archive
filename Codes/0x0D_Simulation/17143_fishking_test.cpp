#include <bits/stdc++.h>
using namespace std;

struct shark {
    int a, b, c;
};

int main() {
    vector<int> v;
    // v.push_back(3);

    // for (auto i : v) {
    //     i = 5;
    // }

    // cout << v[0];

    // for (auto & i : v) {
    //     i = 5;
    // }
    // cout << v[0];

    // shark arr[3] = {{1,1,1}, {2,2,2}, {3,3,3}};

    // arr[0].a = 4;

    // cout << arr[0].a;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (auto & i : v) {
        cout << i << ' ';
    }
    cout << '\n';
    
    for (auto & i : v) {
        cout << i << ' ';
        v.push_back(4);
    }
    cout << '\n';

    for (auto & i : v) {
        cout << i << ' ';
    }

    
}