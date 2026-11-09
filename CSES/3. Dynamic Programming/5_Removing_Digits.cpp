#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll maxi(ll n)
{
    ll m = 0;
    while (n)
    {
        m = max(m, n % 10);
        n /= 10;
    }
    return m;
}

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    while (n)
    {
        ans++;
        n -= maxi(n);
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}