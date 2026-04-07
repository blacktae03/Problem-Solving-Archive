#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt = 0;

    bool test[270] = {0,};
    bool test2[270] = {0,};
    bool test3[270] = {0,};

    fill (test+1, test+270, 1);
    fill (test2+2, test2+270, 1);
    fill (test3+3, test3+270, 1);

    
    do {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 30; j++) {
                cnt++;
            }
        }
        
    } while(next_permutation(test, test+270));
    do {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 30; j++) {
                cnt++;
            }
        }
        
    } while(next_permutation(test2, test2+270));
    do {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 30; j++) {
                cnt++;
            }
        }
        
    } while(next_permutation(test3, test3+270));

    cout << cnt;
}