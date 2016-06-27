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

ll gcd(ll a, ll b)
{
  return b == 0 ? a : gcd(b , a % b);
}

ll lcm(ll a, ll b)
{
  return a / gcd(a, b) * b;
}

int main()
{
  ll n,a,b,p,q;

  cin >> n >> a >> b >> p >> q;
  ll largestCommonDivisor = lcm(a, b);
  ll countLcm = n / largestCommonDivisor;
  ll countRed = n / a - countLcm;
  ll countBlue = n / b - countLcm;

  ll ans = countLcm * max(p, q) + countRed * p + countBlue * q;
  cout << ans << endl;

}