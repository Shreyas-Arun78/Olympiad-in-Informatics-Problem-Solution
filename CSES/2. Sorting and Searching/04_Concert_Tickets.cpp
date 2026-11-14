#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{

    ll n, m;
    cin >> n >> m;

    multiset<ll> a;
    while (n--)
    {
        ll x;
        cin >> x;
        a.insert(x);
    }

    while(m--)
    {
        ll x;cin>>x;
        auto it = a.upper_bound(x);
        if(it==a.begin())
        {
            cout<<-1<<'\n';
            continue;
        }
        it--;
        cout<<*it<<'\n';
        a.erase(it);
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