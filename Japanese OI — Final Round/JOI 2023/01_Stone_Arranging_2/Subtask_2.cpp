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

    ll x = v[0];
    ll k = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            k = i;
        }
    }
    for (int i = 0; i <= k; i++)
    {
        v[i] = x;
    }
    for (auto &i : v)
    {
        cout << i << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}