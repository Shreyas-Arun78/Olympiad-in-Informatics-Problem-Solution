#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    vector<ll> in(x), out(y);
    for (int i = 0; i < x; i++)
    {
        cin >> in[i];
    }
    for (int j = 0; j < y; j++)
    {
        cin >> out[j];
    }

    sort(in.begin(), in.end());
    sort(out.begin(), out.end());

    ll ans = LLONG_MAX;
    for (auto &[a, b] : v)
    {
        ll t1 = lower_bound(in.begin(), in.end(), a) - in.begin();
        ll t2 = lower_bound(out.begin(), out.end(), b) - out.begin();
        if (t2 >= y)
        {
            continue;
        }
        if (t1 >= x)
        {
            t1--;
        }
        if (in[t1] > a)
        {
            if (t1 != 0)
            {
                t1--;
            }
            else
            {
                continue;
            }
        }
        ll T1 = in[t1];
        ll T2 = out[t2];
        ans = min(ans, T2 - T1 + 1);
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