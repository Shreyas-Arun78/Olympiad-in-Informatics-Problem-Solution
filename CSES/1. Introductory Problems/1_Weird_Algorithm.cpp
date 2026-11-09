/**
  - Author : Shreyas Arun
**/

#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    long long n;
    cin >> n;
    while (true)
    {
        cout << n << ' ';
        if (n == 1)
            return;
        n = (n & 1 ? ((n * 3) + 1) : (n / 2));
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}