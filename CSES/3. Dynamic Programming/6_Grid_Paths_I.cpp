#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));

    for (auto &i : v)
    {
        for (auto &j : i)
            cin >> j;
    }

    vector<ll> dp(n);
    for (int i = 0; i < n; i++)
    {
        ll prev = 0;
        for (int j = 0; j < n; j++)
        {
            if (!i)
            {
                if (!j)
                {
                    dp[j] = (v[i][j] == '.');
                    continue;
                }
                else
                {
                    dp[j] = (dp[j - 1] && (v[i][j] == '.'));
                }
            }
            else if (!j)
            {
                dp[j] = (dp[j] && (v[i][j] == '.'));
            }
            else
            {
                if (v[i][j] == '*')
                {
                    dp[j] = 0;
                }
                else
                {
                    dp[j] = (dp[j] + dp[j - 1]) % mod;
                }
            }
            prev = dp[j];
        }
    }
    cout << dp[n - 1];
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