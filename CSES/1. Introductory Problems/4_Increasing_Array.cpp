/**
 * author : Shreyas Arun :)
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ll y;
    cin >> y;
    n--;
    while (n--)
    {
        ll x;
        cin >> x;
        if (x >= y)
        {
            y = max(y,x);
            continue;
        }
        ans += y - x;
        y = max(y, x);
    }
    cout << ans << '\n';
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}