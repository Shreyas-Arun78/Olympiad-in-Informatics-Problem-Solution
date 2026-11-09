#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = -1e18;

void solve()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> h(n), s(n);
    for (auto &i : h)
        cin >> i;
    for (auto &i : s)
        cin >> i;

    vector<ll> dp(x + 1, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = x;j>=h[i];j--)
        {
           if(j-h[i]==inf)
           {
                dp[j] = max(dp[j],s[i]);
           }
           else
           {
            dp[j] = max(dp[j],s[i]+dp[j-h[i]]);
           }

        }
    }
    ll ans = 0;
    for (int i = 0; i <= x; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
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