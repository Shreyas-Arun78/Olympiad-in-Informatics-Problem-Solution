#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;

struct seg_tree
{
    ll n;
    vector<ll> tree;

    seg_tree(ll n)
    {
        this->n = n;
        tree.assign(4 * n, 0);
    }
    void update(ll node, ll l, ll r, ll pos,ll val)
    {
        if (l == r)
        {
            tree[node]+=val;
            return;
        }
        ll mid = l + (r - l) / 2;
        if (pos <= mid)
        {
            update((node << 1) + 1, l, mid, pos,val);
        }
        else
        {
            update((node<<1) + 2, mid + 1, r, pos,val);
        }
        tree[node] = tree[(node << 1) + 1] + tree[(node << 1) + 2];
    }
    ll query(ll node, ll l , ll r, ll ql , ll qr)
    {
        if(l>qr || r<ql)
        {
            return 0;
        }
        if(ql<=l && qr>=r)
        {
            return tree[node];
        }
        ll mid= l + (r-l)/2;
        ll left_child  = query((node<<1)+1,l,mid, ql, qr);
        ll right_child = query((node<<1)+2,mid+1,r,ql,qr);
        return left_child + right_child;
    }
};

void solve()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    vector<ll> x = v;
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());

    vector<ll> comp(n);

    for (int i = 0; i < n; i++)
    {
        comp[i] = lower_bound(x.begin(), x.end(), v[i]) - x.begin()+1;
    }
    seg_tree tree(n+1);
    vector<ll>dp(n);

    for(int i = 0;i<n;i++)
    {
        ll hell = tree.query(0,0,n,0,comp[i]-1);
        dp[i] = (1 + hell)%mod;
        tree.update(0,0,n,comp[i],dp[i]);
    }
    ll ans = 0;

    for(int i = 0;i<n;i++)
    {
        ans = (ans+dp[i])%mod;
    }

    cout<<ans<<'\n';

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