// problem link - https://cses.fi/problemset/task/1660/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    int j = 0;
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += v[i];

        while (j <= i && sum > x)
        {
            sum -= v[j++];
        }
        if (sum == x)
        {
            ans++;
        }
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