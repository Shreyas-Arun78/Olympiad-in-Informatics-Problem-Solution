#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mini = LLONG_MIN;
const ll maxi = LLONG_MAX;
 
struct hell
{
    ll u, v, x;
};
 
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<hell> edges(m);
    vector<vector<ll>> graph(n);
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w, --u, --v;
        edges[i] = {u, v, w};
        graph[u].push_back(v);
    }
    vector<ll> dist(n, mini);
    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto &e : edges)
        {
            ll u = e.u;
            ll v = e.v;
            ll w = e.x;
 
            if (dist[u] != mini && dist[u] + w > dist[v])
            {
                dist[v] = dist[u] + w;
                if (i == n - 1)
                {
                    dist[v] = maxi;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto &e : edges)
        {
            ll u = e.u;
            ll v = e.v;
            if (dist[u] == maxi)
            {
                dist[v] = maxi;
            }
        }
    }
    if (dist[n - 1] == mini || dist[n - 1] >= maxi)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << dist[n - 1] << '\n';
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
