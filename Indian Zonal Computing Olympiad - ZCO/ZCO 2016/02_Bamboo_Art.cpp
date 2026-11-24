#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    sort(v.begin(),v.end());

    vector<unordered_map<ll, ll>> dp(n + 1);
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            ll cnt = 1;
            ll diff = v[i] - v[j];
            if (dp[j].count(diff))
            {
                cnt = dp[j][diff];
            }
            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
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