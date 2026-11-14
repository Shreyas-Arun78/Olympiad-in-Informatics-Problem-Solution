#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll x, n;
    cin >> x >> n;
    set<ll> s;
    multiset<ll> gap;
    s.insert(0);
    s.insert(x);
    gap.insert(x);
    while (n--)
    {
        ll p;
        cin >> p;
        auto ub = s.upper_bound(p);
        ll r = *ub,l = *(--ub);
        gap.erase(gap.find(r - l));
        gap.insert(p - l);
        gap.insert(r - p);
        cout << *gap.rbegin() << ' ';
        s.insert(p);
    }
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