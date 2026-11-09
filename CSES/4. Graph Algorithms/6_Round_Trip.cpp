#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<vector<ll>> adjL;
vector<bool> visited;
vector<ll> parent;
ll start = -1, e = -1;
 
bool dfs(ll nodes, ll par)
{
    visited[nodes] = true;
    for (auto &neigh : adjL[nodes])
    {
        if (neigh == par)
        {
            continue;
        }
        if (visited[neigh])
        {
            start = neigh;
            e = nodes;
            return true;
        }
        else
        {
            parent[neigh] = nodes;
            if (dfs(neigh, nodes))
            {
                return true;
            }
        }
    }
    return false;
}
 
void solve()
{
    ll n, m;
    cin >> n >> m;
    adjL.resize(n + 1);
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);
 
    while (m--)
    {
        ll u, v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
 
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && dfs(i, -1))
        {
            break;
        }
    }
 
    if (start == -1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
 
    vector<ll> cycle;
    ll curr = e;
    cycle.push_back(start);
    while (curr != start)
    {
        cycle.push_back(curr);
        curr = parent[curr];
    }
    cycle.push_back(start);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << '\n';
 
    for (auto i : cycle)
    {
        cout << i << ' ';
    }
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}