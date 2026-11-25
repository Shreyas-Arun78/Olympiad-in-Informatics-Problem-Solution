#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll h, w;
    cin >> h >> w;

    vector<vector<char>> v(h, vector<char>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<ll>> o(h, vector<ll>(w)), I(h, vector<ll>(w));

    for (int i = 0; i < h; i++)
    {
        ll cnt = 0;
        for (int j = w - 1; j >= 0; j--)
        {
            if (v[i][j] == 'O')
            {
                o[i][j] = ++cnt;
            }
            else
            {
                o[i][j] = cnt;
            }
        }
    }
    for (int j = 0; j < w; j++)
    {
        ll cnt = 0;
        for (int i = h - 1; i >= 0; i--)
        {
            if (v[i][j] == 'I')
            {
                I[i][j] = ++cnt;
            }
            else
            {
                I[i][j] = cnt;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (v[i][j] == 'J')
            {
                ans += (o[i][j] * I[i][j]);
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}