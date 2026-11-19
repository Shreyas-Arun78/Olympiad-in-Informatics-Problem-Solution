#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<ll> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ll maxi = 0;
        for (int j = i - 1; j >= max(0LL, i - k); j--)
        {
            maxi = max(maxi, v[j + 1]);
            ll len = i - j;
            dp[i] = max(dp[i], dp[j] + (len * maxi));
        }
    }
    cout << dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    solve();
    return 0;
}