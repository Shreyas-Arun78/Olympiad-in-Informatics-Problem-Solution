#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void dfs(ll node, vector<bool> &visited, vector<vector<ll>> &adj)
{
    visited[node] = true;
    for (auto &i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj);
        }
    }
}
 
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n);
    while (m--)
    {
        ll a, b;
        cin >> a >> b, --a, --b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<ll> ans;
    vector<bool> visited(n, false);
 
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, v);
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() - 1 << '\n';
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}