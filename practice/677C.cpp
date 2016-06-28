#include <iostream>
#include <string>

using namespace std;

int countBit(int arg)
{
    int ret = 0;
    while(arg > 0)
    {
        if(arg % 2 == 1)
        {
            ret++;
        }

        arg >>= 1;
    }

    return ret;
}

int modPow(int base, int pow, int mod)
{
    int ret = 1;
    while(pow > 0)
    {
        if(pow % 2 == 0)
        {
            base = (long long)base * base % mod;
            pow >>= 1;
        }
        else
        {
            ret = (long long)ret * base % mod;
            pow--;
        }
    }

    return ret;
}

int main()
{
    string s;
    cin >> s;
    int countZero = 0;
    for(int i=0;i<s.size();++i)
    {
        int tmp = 0;
        if('0' <= s[i] && s[i] <= '9')
        {
            tmp = s[i] - '0';
        }
        else if('A' <= s[i] && s[i] <= 'Z')
        {
            tmp = s[i] - 'A' + 10;
        }
        else if('a' <= s[i] && s[i] <= 'z')
        {
            tmp = s[i] - 'a' + 36; 
        }
        else
        {
            tmp = s[i] == '-' ? 62 : 63;
        }

        countZero += 6 - countBit(tmp);
    }

    cout << modPow(3, countZero, 1000000007) << endl;
}