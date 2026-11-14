#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void hell(vector<ll> &v)
{
    ll x = v.size();
    if (x == 1)
    {
        cout << v[0] << ' ';
        return;
    }
    for (int i = 1; i < x; i += 2)
    {
        cout << v[i] << ' ';
    }
    vector<ll> d;
    if (x & 1)
    {
        d.push_back(v[x - 1]);
        for (int i = 0; i < x - 1; i+=2)
        {
            d.push_back(v[i]);
        }
    }
    else
    {
        for (int i = 0; i < x; i+=2)
        {
            d.push_back(v[i]);
        }
    }
    hell(d);
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }
    hell(v);
    return;
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