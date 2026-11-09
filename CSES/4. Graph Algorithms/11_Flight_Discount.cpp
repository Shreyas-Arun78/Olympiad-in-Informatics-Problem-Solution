#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll inf = LLONG_MAX;
 
void solve()
{
    ll n, m;
    cin >> n >> m;
 
    vector<vector<pair<ll, ll>>> v(n);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c, --a, --b;
        v[a].push_back({b, c});
    }
 
    vector<vector<ll>> dist(n, vector<ll>(2, inf));
    dist[0][0] = 0;
 
    priority_queue<tuple<ll, ll, int>, vector<tuple<ll, ll, int>>, greater<>> pq;
    pq.push({0, 0, 0});
 
    while (!pq.empty())
    {
        auto [cost, node, used] = pq.top();
        pq.pop();
        if (cost > dist[node][used])
        {
            continue;
        }
        for (auto &[nxt, w] : v[node])
        {
            if (!used)
            {
                if (cost + w < dist[nxt][0])
                {
                    dist[nxt][0] = w + cost;
                    pq.push({dist[nxt][0], nxt, 0});
                }
                if (cost + (w / 2) < dist[nxt][1])
                {
                    dist[nxt][1] = (w / 2) + cost;
                    pq.push({dist[nxt][1], nxt, 1});
                }
            }
            else if (cost + w < dist[nxt][used])
            {
                dist[nxt][used] = w + cost;
                pq.push({dist[nxt][used], nxt, used});
            }
        }
    }
    cout << min(dist[n - 1][1], dist[n - 1][0]) << '\n';
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}