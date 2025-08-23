#include <bits/stdc++.h>
using namespace std;

const int M = 1000003; // 5일 때도 통과
const int a = 1000;

const int MX = 500005; // 최대 삽입 횟수
int head[M];
int pre[MX];
int nxt[MX];
string key[MX];
// int val[MX];
int unused = 0;

int my_hash(string& s){
  int h = 0;
  for(auto x : s)
    h = (h * a + x) % M;
  return h;
}

// key[idx] == k인 idx를 반환, 만약 k가 존재하지 않을 경우 -1을 반환
// key에 대응되는 value를 반환하는게 아니라 인덱스를 반환함에 주의
int find(string k){
    int th = head[my_hash(k)];
    // if (th)
    while (key[th] != k && th != -1) th = nxt[th];
    return th;
}

void insert(string k){
    // 키 값이 같은 게 있는 지 확인
    int th = find(k);
    if (th != -1) {
        val[th] = v;
        return;
    }

    // 키 값이 같은 게 없을 때
    key[unused] = k;
    // val[unused] = v;
    if (key[head[my_hash(k)]] != "") {
        pre[head[my_hash(k)]] = unused;
        nxt[unused] = head[my_hash(k)];
    }
    // else {
    //     pre[unused] = -1;
    //     nxt[unused] = -1;
    // }
    head[my_hash(k)] = unused;
    unused++;
}

void erase(string k){
    int idx = find(k);
    if(idx == -1) return;
    if(pre[idx] != -1) nxt[pre[idx]] = nxt[idx];
    else head[my_hash(k)] = nxt[idx];
    if(nxt[idx] != -1) pre[nxt[idx]] = pre[idx];
}

void show() { // 내가 만든 함수
    cout.setf(ios::left);
    cout.width(10);
    cout << setw(10) << "address" << setw(10) << "key" << setw(10) << "value" << setw(10) << "pre" << setw(10) << "nxt" << setw(10) << "headOrNot" << '\n';
    for (int i = 0; i < unused; i++) {
        cout << setw(10) << i << setw(10) << key[i] << setw(10) << val[i] << setw(10) << pre[i] << setw(10) << nxt[i];
        if (head[my_hash(key[i])] == i) cout << i << '\n';
        else cout << -1 << '\n';
    }
}

void test(){
    insert("orange", 724); // ("orange", 724)
    insert("melon", 20); // ("orange", 724), ("melon", 20)
    assert(val[find("melon")] == 20);
    insert("banana", 52); // ("orange", 724), ("melon", 20), ("banana", 52)
    insert("cherry", 27); // ("orange", 724), ("melon", 20), ("banana", 52), ("cherry", 27)
    insert("orange", 100); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
    assert(val[find("banana")] == 52);
    assert(val[find("orange")] == 100);
    show();
    erase("wrong_fruit"); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
    erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
    show();
  assert(find("orange") == -1);
  erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
  insert("orange", 15); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15)
  assert(val[find("orange")] == 15);
  insert("apple", 36); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36)
  insert("lemon", 6); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36), ("lemon", 6)
  insert("orange", 701);  // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 701), ("apple", 36), ("lemon", 6)
  assert(val[find("cherry")] == 27);
  erase("xxxxxxx");
  assert(find("xxxxxxx") == -1);
  assert(val[find("apple")] == 36);
  assert(val[find("melon")] == 20);
  assert(val[find("banana")] == 52);
  assert(val[find("cherry")] == 27);
  assert(val[find("orange")] == 701);
  assert(val[find("lemon")] == 6);  
  cout << "good!\n";
}

int main(){
  fill(head, head+M, -1);
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  // 아 pre랑 nxt 다 -1로 채우는 지 몰랐네;;; 그럼 더 간단하게 짰지;

  int N; cin >> N;

  for (int i = 0; i < N; i++) {
    string name, enterOrLeave;
    cin >> name >> enterOrLeave;

    if (enterOrLeave == "enter") insert(name);
  }
}