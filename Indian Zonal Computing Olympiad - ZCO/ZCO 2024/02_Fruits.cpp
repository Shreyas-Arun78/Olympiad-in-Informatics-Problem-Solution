#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> a(n, vector<ll>(m));
    multiset<ll> hell[k + 1][2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            hell[a[i][j]][0].insert(i - j);
            hell[a[i][j]][1].insert(i + j);
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ll i, j, x;
            cin >> i >> j >> x, --i, --j;
            ll current = a[i][j];
            a[i][j] = x;
            hell[current][0].erase(hell[current][0].find(i - j));
            hell[current][1].erase(hell[current][1].find(i + j));
            hell[x][0].insert(i-j);
            hell[x][1].insert(i+j);
        }
        else if (t == 2)
        {
            ll u, v;
            cin >> u >> v;

            ll ans = 0LL;
            for (int i = 0; i < 2; i++)
            {
                ll maxU = *hell[u][i].rbegin();
                ll minU = *hell[u][i].begin();

                ll maxV = *hell[v][i].rbegin();
                ll minV = *hell[v][i].begin();

                ans = max({ans, maxU - minV, maxV - minU});
            }
            cout << ans << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}