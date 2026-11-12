#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct hell
{
    ll a, b, c;
};

void solve()
{
    ll n;
    cin >> n;
    vector<hell> v(n);
    for (auto &i : v)
    {
        cin >> i.a >> i.b >> i.c;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = v[i - 1].a + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = v[i - 1].b + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = v[i - 1].c + max(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
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