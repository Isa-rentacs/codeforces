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
    int n;

    cin >> n;
    vector<int> v(n);
    
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if(v.back() == 1){
        for(int i=0;i<n;i++){
            if(i) cout << " ";
            if(i == n-1){
                cout << 2;
            }else{
                cout << 1;
            }
        }
        cout << endl;
    }else{
        for(int i=0;i<n;i++){
            if(i) cout << " ";
            if(i == 0){
                cout << min(1,v[i]);
            }else{
                cout << min(v[i],v[i-1]);
            }
        }
        cout << endl;
    }
}
