#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum = 0;
    int min = 100;
    int num;

    for (int i = 0; i < 7; i++) {
        cin >> num;
        if(num % 2 == 1 ) {
            if (num < min) min = num;
            sum += num;
        }
    }
    
    if(!sum) cout << -1;
    else cout << sum << '\n' << min;
}