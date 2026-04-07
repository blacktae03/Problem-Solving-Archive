#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool mark[5] = {0,0,1,1,1};

    do {
        for (int i = 0; i < 5; i++) cout << mark[i] << ' ';
        cout << '\n';
    } while(next_permutation(mark, mark+5));
    cout << '\n';
    do {
        for (int i = 0; i < 5; i++) cout << mark[i] << ' ';
        cout << '\n';
    } while(next_permutation(mark, mark+5));
}