#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

void solve()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    vector<ll> dp(x + 1,0);
    dp[0] = 1;

    for (auto &j : v)
    {
        for (int i = 1; i <= x; i++)
        {
            if (i - j >= 0)
            {
                dp[i] = (dp[i]+ dp[i - j])%mod;
            }
        }
    }
    cout << (dp[x])%mod << '\n';
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
