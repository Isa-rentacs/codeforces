#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,h,k;
    cin >> n >> h >> k;
    long long ret = 0;
    int a[n] = {};
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }

    for(int i=0;i<n;++i)
    {
        ret += a[i] / k;
        int remaining = a[i] % k;
        if(i != n-1)
        {
            if(remaining + a[i+1] <= h)
            {
                a[i+1] += remaining;
            }
            else
            {
                ret += 1;
            }
        }
        else
        {
            if(remaining != 0)
            {
                ret += 1;
            }
        }
    }

    cout << ret << endl;
}