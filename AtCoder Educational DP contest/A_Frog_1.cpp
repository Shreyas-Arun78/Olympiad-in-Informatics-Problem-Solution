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
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    if (n == 2)
    {
        cout << abs(v[0] - v[1]) << '\n';
        return;
    }
    ll a = 0LL, b = abs(v[0] - v[1]);
    ll c;
    for (int i = 2; i < n; i++)
    {
        ll j1 = abs(v[i] - v[i - 2]) + a;
        ll j2 = abs(v[i] - v[i - 1]) + b;
        c = min(j1, j2);
        a = b;
        b = c;
    }
    cout << min(b,c) << '\n';
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