#include <iostream>

using namespace std;

bool isLeap(int n)
{
    return (n % 4 == 0 && (n % 100 != 0 || n % 400 == 0));
}

int main()
{
    int mod = 0;
    int start, cur;
    cin >> start;
    cur = start;
    while(true)
    {
        mod += isLeap(cur) ? 2 : 1;
        cur++;
        if(mod % 7 == 0 && (isLeap(start) == isLeap(cur))) break;
    }

    cout << cur << endl;
}