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
    ll x = accumulate(v.begin(), v.end(), 0);
    vector<bool> dp(x + 1, false);
    dp[0] = true;

    for (auto &i : v)
    {
        for (int j = x;j>=i;j--)
        {
            dp[j] = dp[j] || dp[j - i];
        }
    }
    ll cnt = count(dp.begin(), dp.end(), 1) - 1;
    cout << cnt << '\n';
    for (int i = 1; i <= x; i++)
    {
        if (dp[i])
        {
            cout << i << ' ';
        }
    }
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