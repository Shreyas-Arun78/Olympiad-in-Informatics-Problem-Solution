#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> days(n);
    for (auto &i : days)
        cin >> i;
    vector<vector<ll>> v(n);
    while (m--)
    {
        ll a, b;
        cin >> a >> b, --a, --b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<ll> hell;
    queue<ll> q;
    vector<bool> visited(n, false);
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (days[i] == -1 && !visited[i])
        {
            q.push(i);
            while (!q.empty())
            {
                ll node = q.front();
                q.pop();
                visited[node] = true;
                hell.push_back(node);
                flag = true;
                for (auto &i : v[node])
                {
                    if (!visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
    if (flag)
    {
        for (auto &i : hell)
        {
            days[i] = -1;
        }
    }


    priority_queue<pair<ll, ll>> pq;
    for (ll i = 0; i < n; i++)
    {
        if (days[i] != -1)
        {
            pq.push({days[i], i});
        }
    }
    while (!pq.empty())
    {
        auto [day, node] = pq.top();
        pq.pop();
        if (day != days[node])
        {
            continue;
        }
        for (auto &i : v[node])
        {
            if(days[i]==-1)continue;
            if (days[i] < day - 1)
            {
                days[i] = day - 1;
                pq.push({days[i], i});
            }
        }
    }

    for (auto &i : days)
    {
        cout << i << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}