#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, q;
    cin >> n >> q;
    ll sum = 0LL;
    map<ll, ll> mp;
    while (n--)
    {
        ll i;
        cin >> i;
        mp[i]++;
        sum += i;
    }

    cout << sum << '\n';

    while (q--)
    {
        ll l, r, j;
        cin >> l >> r >> j;

        ll cnt = 0;

        auto it = mp.lower_bound(l);
        while (it != mp.end() && it->first <= r)
        {
            ll key = it->first;
            ll value = it->second;

            cnt += value;
            sum -= (key * value);
            it = mp.erase(it);
        }
        sum += (cnt * j);
        mp[j] += cnt;
        cout << sum << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}