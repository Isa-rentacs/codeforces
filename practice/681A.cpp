#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool isYes = false;
    for(int x=0;x<n;++x)
    {
        string s;
        int before, after;
        cin >> s >> before >> after;

        if(before >= 2400 && before < after)
        {
            isYes |= true;
        }
        else
        {
            isYes |= false;
        }
    }

    string ans = isYes ? "YES" : "NO";

    cout << ans << endl;
}