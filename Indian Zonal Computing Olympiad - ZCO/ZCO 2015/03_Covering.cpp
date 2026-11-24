/**
 * author : Shreyas Arun :)
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (auto &i : v)
    {
        cin >> i.first >> i.second;
    }

    sort(v.begin(), v.end(),[](auto &a, auto &b) { return a.second < b.second; });

    ll last = -1;
    ll ans = 0;
    for (auto &[l, r] : v)
    {
        if (last < l)
        {
            last = r;
            ans++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}