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
    for (int i = 0; i < n; i++)
    {
        ll x = v[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (v[j] == x)
            {
                break;
            }
        }
        if (j >= 0)
        {
            for (int k = j; k < i; k++)
            {
                v[k] = x;
            }
        }
    }
    for(auto  &i:v)
    {
        cout<<i<<' ';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}