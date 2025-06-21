#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> deck;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        deck.push_back(i+1);

    while(deck.size() > 1) {
        deck.pop_front();
        if(deck.size() == 1) break;
        else {
            deck.push_back(deck.front());
            deck.pop_front();
        }
    }

    cout << deck.back();
}