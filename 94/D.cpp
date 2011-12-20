#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
 
using namespace std;
 
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long
#define FILL(ptr, value) FILL_((ptr), sizeof(ptr)/sizeof(value), (value))
 
template <typename T>
void FILL_(void * ptr, size_t size, T value){
  std::fill((T*)ptr, (T*)ptr+size, value);
}
 
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

int main(void){
  string str;
  cin >> str;
  vector<int> v[26];
  int k;

  cin >> k;

  //alphabetごとのindexをとる
  for(int i=0;i<str.size();i++){
    v[str[i]-'a'].push_back(i);
  }

  for(int i=0;i<26;i++){
    int tmp=0;
    for(int j=0;j<v[i].size();j++){
      tmp += str.size() - v[i][j];
    }
  }
}
