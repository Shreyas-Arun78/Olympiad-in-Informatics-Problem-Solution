#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct hell
{
    ll wt, val;
};

void solve()
{
    ll n, w;
    cin >> n >> w;
    vector<hell> v(n);
    for (auto &i : v)
    {
        cin >> i.wt >> i.val;
    }
    vector<ll> dp(w + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = w; j >= v[i].wt; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i].wt] + v[i].val);
        }
    }
    cout<<dp[w]<<'\n';
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