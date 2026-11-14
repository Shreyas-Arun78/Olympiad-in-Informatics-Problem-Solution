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
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > ans + 1)
        {
            cout << ans + 1 << '\n';
            return;
        }
        ans += v[i];
    }
    cout << ans + 1 << '\n';
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
