/**
 * author : Shreyas Arun :)
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mod = 1e9 + 7;
 
void solve()
{
    ll n;
    cin >> n;
    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans << 1) % mod;
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