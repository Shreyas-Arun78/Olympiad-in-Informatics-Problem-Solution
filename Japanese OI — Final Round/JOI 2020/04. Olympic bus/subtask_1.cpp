#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = LLONG_MAX;

struct Edge
{
    ll u, v, c, d;
};

ll n, m;

vector<Edge> edges;

vector<ll> dikjstra(ll source, ll invert)
{
    vector<vector<pair<ll, ll>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        if (i == invert)
        {
            adj[edges[i].v].push_back({edges[i].u, edges[i].c});
        }
        else
        {
            adj[edges[i].u].push_back({edges[i].v, edges[i].c});
        }
    }

    vector<bool> visited(n, false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, source});
    vector<ll> dist(n, inf);
    dist[source] = 0;
    while (!pq.empty())
    {
        ll node = pq.top().second;
        visited[node] = true;
        pq.pop();
        for (auto &[nxt, d] : adj[node])
        {
            if (!visited[nxt] && dist[node] + d < dist[nxt])
            {
                dist[nxt] = dist[node]+d;
                pq.push({dist[nxt],nxt});
            }
        }
    }
    return dist;
}

void solve()
{
    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].c >> edges[i].d, --edges[i].u, --edges[i].v;
    }

    ll ans = inf;

    auto d1 = dikjstra(0, -1);
    auto d2 = dikjstra(n - 1, -1);

    if (d1[n-1] < inf && d2[0] < inf)
    {
        ans = min(ans, d1[n-1] + d2[0]);
    }

    for (int i = 0; i < m; i++)
    {
        auto d1 = dikjstra(0, i);
        auto d2 = dikjstra(n - 1, i);
        if (d1[n-1] < inf && d2[0] < inf)
        {
            ans = min(ans, d1[n - 1] + d2[0] + edges[i].d);
        }
    }

    cout << (ans == inf ? -1 : ans) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}