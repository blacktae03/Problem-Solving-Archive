#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A[5] = {0,1,2,3,4};
    cout << upper_bound(A, A+5, 5) - lower_bound(A, A+5, 5);
}