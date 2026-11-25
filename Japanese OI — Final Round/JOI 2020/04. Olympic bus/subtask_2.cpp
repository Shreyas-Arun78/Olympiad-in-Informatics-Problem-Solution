#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = LLONG_MAX;

struct Edge
{
    ll u, v, c, d;
};

vector<Edge> edges;

ll n, m;

vector<ll> dikjstra(ll source, vector<vector<pair<ll, ll>>> &adj)
{
    vector<ll> dist(n, inf);
    dist[source] = 0;
    vector<bool> visited(n, false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, source});
    while (!pq.empty())
    {
        ll node = pq.top().second;
        visited[node] = true;
        pq.pop();
        for (auto &[nxt, d] : adj[node])
        {
            if (!visited[nxt] && dist[node] + d < dist[nxt])
            {
                dist[nxt] = dist[node] + d;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    return dist;
}

void solve()
{
    cin >> n >> m;
    edges.resize(m);

    vector<vector<pair<ll, ll>>> adj(n), rev_adj(n);

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].c >> edges[i].d, --edges[i].u, --edges[i].v;
        adj[edges[i].u].push_back({edges[i].v, edges[i].c});
        rev_adj[edges[i].v].push_back({edges[i].u, edges[i].c});
    }

    ll ans = inf;
    auto D1 = dikjstra(0, adj);
    auto Dn = dikjstra(n - 1, adj);
    if (D1[n - 1] < inf && Dn[0] < inf)
    {
        ans = min(ans, D1[n-1] + Dn[0]);
    }

    vector<ll> d1 = dikjstra(0, adj);
    vector<ll> rev_dN = dikjstra(n - 1, rev_adj);
    vector<ll> dN = dikjstra(n - 1, adj);
    vector<ll> rev_d1 = dikjstra(0, rev_adj);

    for (int i = 0; i < m; i++)
    {
        ll c = edges[i].c;
        ll d = edges[i].d;
        ll u = edges[i].u;
        ll v = edges[i].v;
        ll start_to_end = min(d1[n - 1], ((d1[v] < inf && rev_dN[u] < inf) ? d1[v] + c + rev_dN[u] : inf));
        ll end_to_start = min(dN[0], ((dN[v] < inf && rev_d1[u] < inf) ? dN[v] + c + rev_d1[u] : inf));

        if (start_to_end < inf && end_to_start < inf)
        {
            ans = min(ans, start_to_end + end_to_start + d);
        }
    }
    cout<<(ans==inf?-1:ans)<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}