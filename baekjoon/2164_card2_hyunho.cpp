#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> card;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        card.push(i);
    }
    while(1){
        //카드버리기
        if(card.size()==1){
            cout << card.front();
            break;
        }
        card.pop();
        //카드개수1개일때
        //맨위 카드 뒤로 넣기
        card.push(card.front());
        card.pop();
    }
    // cout << card.front();
    return 0;
}