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

int dx[9] = {1,0,-1,1,0,-1,1,0,-1};
int dy[9] = {1,1,1,0,0,0,-1,-1,-1};
ll dp[50][8][8];

int main(){
  string board[8];
  

  //FILL(dp,0);
  dp[0][7][0] = 1;
  vector<pair<int,int> > statues;
  for(int i=0;i<8;i++){
    cin >> board[i];
  }
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(board[i][j] == 'S'){
	statues.PB(MP(i,j));
      }
    }
  }
  for(int i=0;i<49;i++){
    for(int p=0;p<8;p++){
      for(int q=0;q<8;q++){
	for(int d=0;d<9;d++){
	  bool isok = true;
	  if(0 <= p+dx[d] && p+dx[d] < 8 &&
	     0 <= q+dy[d] && q+dy[d] < 8){
	    for(int s=0;s<statues.size();s++){
	      if((p == statues[s].first+i && q == statues[s].second) ||
		 (p == statues[s].first+i+1 && q == statues[s].second)){
		isok = false;
	      }
	    }
	  }else{
	    isok = false;
	  }
	  if(isok){
	    dp[i+1][p][q] += dp[i][p+dx[d]][q+dy[d]];
	  }
	}
      }
    }
    if(dp[i+1][0][7] > 0){
      cout << "WIN" << endl;
      return 0;
    }
  }
  cout << "LOSE" << endl;
}
