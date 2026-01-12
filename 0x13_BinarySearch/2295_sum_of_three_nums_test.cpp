#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A[4] = {0,1,2,3};
    cout << lower_bound(A, A+4, 4) - A;
}