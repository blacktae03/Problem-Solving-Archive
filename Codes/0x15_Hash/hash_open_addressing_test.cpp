#include <bits/stdc++.h>
using namespace std;

const int M = 1000003;
const int a = 1000;
const int EMPTY = -1;
const int OCCUPY = 0;
const int DUMMY = 1;
int status[M]; // EMPTY / OCCUPY / DUMMY
string key[M];
int val[M];

int my_hash(string& s){
  int h = 0;
  for(auto x : s)
    h = (h * a + x) % M;
  return h;
}

// key[idx] == k인 idx를 반환, 만약 k가 존재하지 않을 경우 -1을 반환
// key에 대응되는 value를 반환하는게 아니라 인덱스를 반환함에 주의
int find(string k){
    int th = my_hash(k);
    while (key[th] != k || status[th] != OCCUPY) { // 키값이 k이면서 status가 OCCUPY여야 반복문 탈출
        // if (status[th++] != EMPTY) return -1;
        if (status[th] == EMPTY) return -1;
        th++; // th = (th+1) % M이 맞음.
    }
    return th;
}

void insert(string k, int v){
    int th = my_hash(k);
    if (find(k) != -1) {
        val[find(k)] = v;
        return;
    }

    while(status[th] != EMPTY) th++; // 왜 while(status[th++] != EMPTY) {}라고 하면 안되지???? test.cpp에서 알아냈음.
    // DUMMY에도 넣어도 상관없으므로 == OCCUPY로 넣어도 상관없음.
    status[th] = OCCUPY;
    key[th] = k;
    val[th] = v;
}

void erase(string k){
    int idx = find(k);
    if(idx == -1) return;
    status[idx] = DUMMY;
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
  erase("wrong_fruit"); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
  erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
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
  fill(status, status+M, EMPTY);
  test();
}