#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    vector<vector<ll>> dp(n, vector<ll>(2, LLONG_MAX));
    // case 1- taking first knight
    dp[0][1] = v[0];
    dp[0][0] = LLONG_MAX;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = v[i] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    ll ans = min(dp[n - 1][1], dp[n - 1][0]);
    dp.assign(n, vector<ll>(2, LLONG_MAX));
    // case 2 - not taking first knight
    dp[0][0] = 0;
    dp[0][1] = LLONG_MAX;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = v[i] + min(dp[i - 1][1], dp[i - 1][0]);
    }
    ans = min(ans, dp[n - 1][1]);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}