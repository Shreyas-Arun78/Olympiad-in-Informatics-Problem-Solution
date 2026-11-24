#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, S;
    cin >> n >> S;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    unordered_map<ll, ll> mp;

    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll missing = S - v[i] - v[j];
            auto it = mp.find(missing);
            if (it != mp.end())
            {
                ans+=mp[missing];
            }
        }
        for (ll j = 0; j < i; j++)
        {
            ll x = v[i] + v[j];
            mp[x]++;
        }
    }
    cout << ans << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}