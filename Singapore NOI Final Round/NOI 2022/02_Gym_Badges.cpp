#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

struct hell
{
    ll sum, x, l;
    bool operator<(const hell &other) const
    {
        return tie(sum, l) < tie(other.sum, other.l);
    }
};

void solve()
{
    ll n;
    cin >> n;
    vector<hell> v(n);
    for (auto &i : v)
        cin >> i.x;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].l;
        v[i].sum = v[i].x + v[i].l;
    }
    sort(v.begin(), v.end());
    priority_queue<pair<ll, ll>> pq;
    pq.push({v[0].x, v[0].l});
    ll sum = v[0].x;
    for (int i = 1; i < n; i++)
    {
        auto [bx, bl] = pq.top();
        ll x = v[i].x;
        ll l = v[i].l;
        if(sum<=l) // adding
        {
            sum+=x;
            pq.push({x,l});
        }
        else if(bx>x) // replacing
        {
            sum-=bx;
            sum+=x;
            pq.push({x,l});
            pq.pop();
        }
    }
    cout<<pq.size()<<'\n';
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