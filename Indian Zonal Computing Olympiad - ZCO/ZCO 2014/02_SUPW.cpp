#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = LLONG_MAX;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(3,inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = v[i] + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][1];
    }
    ll ans = min({dp[n][0], dp[n][1], dp[n][2]});
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}