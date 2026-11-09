#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll inf = LLONG_MAX;
 
void solve()
{
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> floyd(n + 1, vector<ll>(n + 1, inf));
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        floyd[a][b] = floyd[b][a] = min(floyd[a][b], c);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    floyd[i][j] = floyd[j][i] = 0;
                    continue;
                }
                if (floyd[i][k] == inf || floyd[k][j] == inf)
                {
                    continue;
                }
                if (floyd[i][j] > floyd[i][k] + floyd[k][j])
                {
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
                }
            }
        }
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << (floyd[a][b] == inf ? -1 : floyd[a][b]) << '\n';
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}