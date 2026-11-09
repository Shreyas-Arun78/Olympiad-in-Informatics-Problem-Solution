#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<vector<ll>> tree;
vector<ll> ans;
 
ll dfs(ll node)
{
    ll sz = 1;
    for (auto &i : tree[node])
        sz += dfs(i);
    ans[node] = sz - 1;
    return sz;
}
 
void solve()
{
    ll n;
    cin >> n;
    tree.resize(n);
    ans.resize(n);
    for (int i = 1; i < n; i++)
    {
        ll x;
        cin >> x, --x;
        tree[x].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}