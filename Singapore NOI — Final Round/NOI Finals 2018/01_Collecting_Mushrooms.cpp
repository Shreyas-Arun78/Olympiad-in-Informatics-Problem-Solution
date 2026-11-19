#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m, d, k;
    cin >> n >> m >> d >> k;
    vector<vector<ll>> v(n + 1, vector<ll>(m + 1, 0));
    vector<vector<char>> ch(n + 1, vector<char>(m + 1));
    vector<pair<ll, ll>> mush;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> ch[i][j];
            if (ch[i][j] == 'S')
            {
                v[i][j] = 1;
            }
            if (ch[i][j] == 'M')
            {
                mush.push_back({i, j});
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            // cout << v[i][j] << ' ';
        }
        // cout << '\n';
    }

    ll ans = 0;

    for (auto &[x, y] : mush)
    {
        // left most
        ll x1 = max(1LL, x - d), y1 = max(1LL, y - d);
        ll x2 = min(n, x + d), y2 = min(m, y + d);
        ll sum = v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1];
        if (sum >= k)
        {
            ans++;
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}