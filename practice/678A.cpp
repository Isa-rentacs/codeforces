#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int ans = (n/k + 1) * k;
    cout << ans << endl;
}