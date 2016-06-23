#include <vector>
#include <set>
#include <deque>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool isYes = false;
    for(int i=0;i*1234567 <= n;++i)
    {
        for(int j=0;j*123456 <= n - i * 1234567;++j)
        {
            if((n - i * 1234567 - j * 123456) % 1234 == 0)
            {
                isYes = true;
                break;
            }
        }
        if(isYes) break;
    }
    string ans = isYes ? "YES" : "NO";
    cout << ans << endl;
}