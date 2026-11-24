#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            int x;
            cin >> x;
            v[i][j] = !x;
            v[i][j] = v[i][j] + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll cal = v[c][d] - v[c][b - 1] - v[a - 1][d] + v[a - 1][b - 1];
        cout << (cal ? 0 : 1) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
