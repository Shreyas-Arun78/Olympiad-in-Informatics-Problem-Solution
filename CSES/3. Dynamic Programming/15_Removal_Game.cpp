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

    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; j++, i++)
        {
            if (g == 0)
            {
                dp[i][j] = v[i];
            }
            else if (g == 1)
            {
                dp[i][j] = max(v[i], v[j]);
            }
            else
            {
                ll cal1 = v[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                ll cal2 = v[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(cal1, cal2);
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
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