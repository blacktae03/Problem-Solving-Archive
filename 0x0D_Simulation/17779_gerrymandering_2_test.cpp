#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum[6] = {0, 1, 4, 3, 2, 9};

    cout << *min_element(sum+1, sum+6);

    bool b = 0;
    b = !b;
    cout << b;
    b = !b;
    cout << b;


}