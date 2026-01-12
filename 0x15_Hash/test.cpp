#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i = 0;
    int j = 0;

    while(i != 5) i++;
    while(j++ != 5) {}
    // 이유 : while의 실행문을 n번 실행한다고 할 때, 조건문은 n+1번 확인한다.
    // j = 0 -> {} (j = 1) -> 
    // j = 1 -> {} (j = 2) -> 
    // j = 2 -> {} (j = 3) -> 
    // j = 3 -> {} (j = 4) -> 
    // j = 4 -> {} (j = 5) -> 
    // j = 5 -> x (j = 6)
    
    // i = 0 -> i++ (i = 1) ->
    // i = 1 -> i++ (i = 2) ->
    // i = 2 -> i++ (i = 3) ->
    // i = 3 -> i++ (i = 4) ->
    // i = 4 -> i++ (i = 5) ->
    // i = 5 -> x (i = 5)
    // 개레전드네 진짜;
    cout << i << '\n' << j;


    // 아니 그러면 내가 자주 쓰는 while(M--) 이것도 실행하면 M이 -1이겠네? 당연히 0이 되어 있겠지 생각했었음.
    int M = 5;
    while(M--) {
        cout << "run\n";
    }
    cout << M;

    string str;

    cin >> str;

    cout << str;

}