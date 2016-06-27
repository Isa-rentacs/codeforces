#include <map>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    map<int,int> m;
    int disc = 0;
    int sum = 0;
    for(int i=0;i<5;++i)
    {
        m[a[i]]++;
        sum += a[i];
    }

    for(auto it = m.begin(); it != m.end(); ++it)
    {
        if((*it).second == 2)
        {
            disc = max(disc, (*it).first * 2);
        }
        else if((*it).second >= 3)
        {
            disc = max(disc, (*it).first * 3);
        }
    }
    cout << (sum - disc) << endl;
}