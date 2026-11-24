#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, a;
    cin >> n >> a;
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll m = v.size();
    vector<ll> ans(a + 1, 0);
    for (int k = 0; k <= a; k++)
    {
        ll i = 0;
        ll cnt = 0;
        while (i < m)
        {
            cnt++;
            ll end = v[i] + k;
            i = upper_bound(v.begin(), v.end(), end) - v.begin();
        }

        ans[k] = cnt;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll f;
        cin >> f;
        if (f >= n)
        {
            cout << 0 << '\n';
            continue;
        }
        ll hell = 0;
        ll l = 0, r = a;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            if (ans[mid]<=f)
            {
                hell = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << hell << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}