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
    vector<ll> lis;
    lis.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        ll ub = upper_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        if (ub>=lis.size())
        {
            lis.push_back(v[i]);
        }
        else
        {
            lis[ub] = v[i];
        }
    }
    cout << lis.size() << '\n';
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