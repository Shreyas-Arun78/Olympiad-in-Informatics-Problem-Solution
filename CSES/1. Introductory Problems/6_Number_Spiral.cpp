#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
void solve()
{
    ll x, y;
    cin >> x >> y;
    
    ll k = max(x, y);
    ll term = ((k - 1) * k) + 1;
    ll dif = abs(x - y);
 
    cout << ((((y > x) && !(y & 1)) || ((x > y) && (x & 1))) ? term - dif : term + dif) << '\n';
 
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}