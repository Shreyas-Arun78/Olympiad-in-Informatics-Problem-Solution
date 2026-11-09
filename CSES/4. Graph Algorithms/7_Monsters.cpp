#include <bits/stdc++.h>
using namespace std;
 
vector<pair<int, int>> change = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
vector<char> dir = {'L', 'R', 'U', 'D'};
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    pair<int, int> s_pos, e_pos = {-1, -1};
    vector<pair<int, int>> monsters;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
            {
                s_pos = {i, j};
            }
            else if (v[i][j] == 'M')
            {
                monsters.push_back({i, j});
            }
        }
    }
 
    if (s_pos.first == 0 || s_pos.second == 0 || s_pos.first == (n - 1) || s_pos.second == (m - 1))
    {
        cout << "YES\n"
             << 0 << '\n';
        return;
    }
 
    vector<vector<int>> magnitude(n, vector<int>(m, INT_MAX)), go(n, vector<int>(m, INT_MAX));
    vector<vector<char>> path(n, vector<char>(m, '|'));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
 
    queue<pair<int, int>> q;
    for (auto &[x, y] : monsters)
    {
        q.push({x, y});
        magnitude[x][y] = 0;
    }
 
    vector<vector<bool>> used(n, vector<bool>(m, false));
 
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        used[node.first][node.second] = true;
        for (int i = 0; i < 4; i++)
        {
            int dx = node.first + change[i].first;
            int dy = node.second + change[i].second;
            if (dx < n && dx >= 0 && dy < m && dy >= 0 && v[dx][dy] != '#' && !used[dx][dy] && magnitude[dx][dy] == INT_MAX)
            {
                q.push({dx, dy});
                used[dx][dy] = true;
                magnitude[dx][dy] = min(magnitude[dx][dy], magnitude[node.first][node.second] + 1);
            }
        }
    }
    go[s_pos.first][s_pos.second] = 0;
    q.push(s_pos);
    bool flag = false;
    while (!q.empty() && !flag)
    {
        auto node = q.front();
        visited[node.first][node.second] = true;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = node.first + change[i].first;
            int dy = node.second + change[i].second;
 
            if (dx < n && dx >= 0 && dy < m && dy >= 0 && v[dx][dy] == '.' && !visited[dx][dy] && magnitude[dx][dy] > (go[node.first][node.second] + 1))
            {
                path[dx][dy] = dir[i];
                q.push({dx, dy});
                go[dx][dy] = 1 + go[node.first][node.second];
                visited[dx][dy] = true;
                if (dx == 0 || dy == 0 || dy == (m - 1) || dx == (n - 1))
                {
                    e_pos = {dx, dy};
                    flag = true;
                    break;
                }
            }
        }
    }
 
    if (!flag)
    {
        cout << "NO\n";
        return;
    }
 
    string journey = "";
    while (e_pos != s_pos)
    {
        auto [i, j] = e_pos;
        char ch = path[i][j];
        journey += path[i][j];
        if (ch == 'U')
            i++;
        else if (ch == 'D')
            i--;
        else if (ch == 'L')
            j++;
        else if (ch == 'R')
            j--;
        e_pos = {i, j};
    }
 
    reverse(journey.begin(), journey.end());
    cout << "YES\n";
    cout << journey.size() << '\n'
         << journey << '\n';
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}