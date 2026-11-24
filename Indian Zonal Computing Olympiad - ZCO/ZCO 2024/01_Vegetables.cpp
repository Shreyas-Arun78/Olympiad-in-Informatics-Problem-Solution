#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<pair<ll, ll>> v(n);
    for (auto &i : v)
        cin >> i.first;
    for (auto &i : v)
        cin >> i.second;

    for (int i = 0; i < n; i++)
    {
        v[i] = {max(v[i].first, v[i].second), min(v[i].first, v[i].second)};
    }
    sort(v.rbegin(), v.rend());
    vector<ll> capacity(n), water(n);
    capacity[0] = v[0].second;
    water[0] = v[0].first * v[0].second;
    for (int i = 1; i < n; i++)
    {
        capacity[i] = capacity[i - 1] + v[i].second;
        water[i] = water[i - 1] + (v[i].first * v[i].second);
    }

    while (q--)
    {
        ll x;
        cin >> x;
        ll ub = upper_bound(capacity.begin(), capacity.end(), x) - capacity.begin();
        if (ub >= n)
        {
            cout << 0 << '\n';
            continue;
        }
        ll saved = 0;
        if(ub==0)
        {
            saved = x*v[0].first;
        }
        else
        {
            ll full_saved = water[ub-1];
            ll remaining_upgrades = x-capacity[ub-1];
            ll partial_saved = remaining_upgrades *v[ub].first;
            saved+= full_saved+ partial_saved;
        }
        cout<<water[n-1]-saved<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}