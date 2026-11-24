#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, k, b;

struct person
{
    ll h, w;
};

vector<person> v;
bool check(ll t)
{
    vector<pair<ll, ll>> hell;
    for (int i = 0; i < n; i++)
    {
        ll x = (t + b - 1) / 2;
        ll A = min(v[i].h, v[i].w);
        ll B = max(v[i].h, v[i].w);
        ll L = max(0LL, A - x);
        ll R = min(k - 1, B + x);
        if (L <= R)
        {
            hell.push_back({L, 1});
            hell.push_back({R + 1, -1});
        }
    }
    sort(hell.begin(), hell.end());
    ll cnt = 0;
    for (auto &[x, y] : hell)
    {
        cnt += y;
        if (cnt >= m)
            return true;
    }
    return false;
}

void solve()
{
    cin >> n >> m >> k >> b;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].h >> v[i].w;
    }
    ll ans = 0;
    ll l = 0, r = 2e9;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
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