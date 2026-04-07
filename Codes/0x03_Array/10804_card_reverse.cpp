#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cards[21] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int start, end, tmp;

    for (int i = 0; i < 10; i++) {
        cin >> start >> end;
        while (end - start >= 1) {
            tmp = cards[start];
            cards[start] = cards[end];
            cards[end] = tmp;
            start++;
            end--; // reverse(cards+start, cards+end+1); 하면 끝난다는데?
        }
    }
    for (int j = 1; j < 21; j++) {
        cout << cards[j] << " ";
    }
    
}