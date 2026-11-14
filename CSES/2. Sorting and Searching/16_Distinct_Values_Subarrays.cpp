#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    map<ll, ll> mp;
    ll i = 0, j = 0;
    ll ans = 0;
    while (j < n)
    {
        mp[v[j]]++;
        while (mp[v[j]] > 1)
        {
            mp[v[i]]--;
            if (mp[v[i]] == 0)
            {
                mp.erase(v[i]);
            }
            i++;
        }
        ans += mp.size();
        j++;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}