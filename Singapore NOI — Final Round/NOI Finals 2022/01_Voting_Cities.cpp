#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct state
{
    ll d, node;
    int mask;
    bool operator>(const state &other) const
    {
        return tie(d, node, mask) > tie(other.d, other.node, other.mask);
    }
};

void solve()
{
    ll n, e, k;
    cin >> n >> e >> k;
    vector<vector<pair<ll, ll>>> v(n), rev(n);
    vector<ll> city(k);
    for (int i = 0; i < k; i++)
    {
        cin >> city[i];
    }
    while (e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        rev[b].push_back({a, w});
    }
    priority_queue<state, vector<state>, greater<state>> pq;
    vector<vector<ll>> dist(n, vector<ll>(32, LLONG_MAX));
    for (int i = 0; i < k; i++)
    {
        pq.push({0LL, city[i], 0});
        dist[city[i]][0] = 0LL;
    }

    vector<vector<bool>> visited(n, vector<bool>(32, false));

    while (!pq.empty())
    {
        state cur = pq.top();
        int mask = cur.mask;
        pq.pop();
        if (cur.d != dist[cur.node][cur.mask])
        {
            continue;
        }
        for (auto &i : rev[cur.node])
        {
            ll d = i.second;
            ll nxt = i.first;
            if (dist[nxt][mask] > cur.d + d)
            {
                dist[nxt][mask] = cur.d + d;
                pq.push({dist[nxt][mask], nxt, mask});
            }
            for (int t = 0; t < 5; t++)
            {
                if (mask & (1 << t))
                    continue;
                int newMask = mask | (1 << t);
                ll newCost = cur.d + d * (9 - t) / 10;
                if (dist[nxt][newMask] > newCost)
                {
                    dist[nxt][newMask] = newCost;
                    pq.push({newCost, nxt, newMask});
                }
            }
        }
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll s;
        cin >> s;
        vector<ll> p(5);
        for (auto &i : p)
            cin >> i;
        ll ans = LLONG_MAX;
        for (int mask = 0; mask < (1 << 5); mask++)
        {
            if (dist[s][mask] == LLONG_MAX)
                continue;
            ll total = dist[s][mask];
            bool valid = true;
            for (int i = 0; i < 5; i++)
            {
                if ((mask & (1 << i)))
                {
                    if (p[i] == -1)
                    {
                        valid = false;
                        break;
                    }
                    total += p[i];
                }
            }
            if (valid)
            {
                ans = min(ans, total);
            }
        }
        cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}