#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    vector<vector<ll>> dp(n, vector<ll>(m + 2, 0));
    if (!v[0])
    {
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = 1;
        }
    }
    else
    {
        dp[0][v[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (!v[i])
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
            }
        }
        else
        {
            dp[i][v[i]] = (dp[i - 1][v[i] - 1] + dp[i - 1][v[i]] + dp[i - 1][v[i] + 1]) % mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n - 1][i]) % mod;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}