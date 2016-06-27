#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;

    int c[n];
    bool b[n] = {};
    int ans = 0;
    for(int i=0;i<n;++i)
    {
        cin >> c[i];
    }

    int range = min(p-1, n-p);

    for(int i=1;i<=range;++i)
    {
        if(c[p-1-i] + c[p-1+i] == 2)
        {
            ans += 2;
        }
    }

    for(int i=0;i<n;i++)
    {
        if((i < p - 1 - range || p - 1 + range < i) || i == (p - 1))
        {
            ans += c[i];
        }
    }

    cout << ans << endl;
}