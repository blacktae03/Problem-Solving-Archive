#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    int num[9] = {0,};

    cin >> N;

    for (auto c : N) {
        if(c=='9') num[6]++;
        else num[c-'0']++;
    }

    num[6] = (num[6]+1)/2;

    auto max = max_element(begin(num), end(num));

    cout << *max;
}