#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
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
 
    vector<ll> color(n, -1);
    vector<bool> visited(n, false);
 
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while (!q.empty())
            {
                ll node = q.front();
                q.pop();
                visited[node] = true;
                for (auto &j : v[node])
                {
                    if (color[j] == -1)
                    {
                        color[j] = (color[node] % 2) + 1;
                        q.push(j);
                    }
                    else if (color[j] == color[node])
                    {
                        cout << "IMPOSSIBLE\n";
                        return;
                    }
                }
            }
        }
    }
    for (auto &i : color)
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