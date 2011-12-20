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

int main(){
  int n,m;
  int x,y;
  
  cin >> n >> m;
  int table[n][n];
  int count[n];
  int ret=0;
  memset(table,0,sizeof(table));
  memset(count,0,sizeof(count));
  for(int i=0;i<m;i++){
    cin >> x >> y;
    table[x-1][y-1] = 1;
    table[y-1][x-1] = 1;
    count[x-1]++; count[y-1]++;
  }
  
  bool isended=false;
  while(!isended){
    isended = true;
    vector<int> remove;
    for(int i=0;i<n;i++){
      if(count[i] == 1){
	remove.push_back(i);
	isended = false;
      }
    }
    if(isended) break;
    ret++;
    for(int i=0;i<remove.size();i++){
      //dump(remove[i]);
      for(int j=0;j<n;j++){
	if(table[remove[i]][j]){
	  count[remove[i]]--;
	  count[j]--;
	}
      }
    }
  }
  cout << ret << endl;
}
