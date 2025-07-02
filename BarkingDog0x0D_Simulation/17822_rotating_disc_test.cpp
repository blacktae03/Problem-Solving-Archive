#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v[2];
    v[0] = {0,1,2,3,4,5};
    v[1] = {0,1,2,3,4,5};
    for (int i : v[0]) cout << i << ' ';
    cout <<'\n';
    rotate(v[0].begin()+1, v[0].end()-1, v[0].end());
    for (int i : v[0]) cout << i << ' ';
    cout <<'\n';
    
}