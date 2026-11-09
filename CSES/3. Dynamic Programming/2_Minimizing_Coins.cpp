#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

void solve()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    vector<ll> dp(x + 1, inf);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (auto &j : v)
        {
            if (i - j >= 0)
            {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }
    cout << (dp[x] == inf ? -1 : dp[x]) << '\n';
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