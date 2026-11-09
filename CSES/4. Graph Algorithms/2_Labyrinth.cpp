/**
 * author : Shreyas Arun :)
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<char> dir = {'L', 'R', 'U', 'D'};
vector<pair<int, int>> walk = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
 
void solve()
{
    int n, m;
    cin >> n >> m;
 
    vector<vector<char>> v(n, vector<char>(m)), path(n, vector<char>(m, '$'));
 
    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
            {
                start = {i, j};
            }
            else if (v[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }
 
    path[start.first][start.second] = '@';
    queue<pair<int, int>> q;
    q.push(start);
    bool flag = false;
 
    vector<vector<bool>> visited(n, vector<bool>(m, false));
 
    while (!q.empty())
    {
        pair<int, int> node = q.front();
        int x = node.first;
        int y = node.second;
        visited[x][y] = true;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = walk[i].first;
            int dy = walk[i].second;
            int delx = x + dx;
            int dely = y + dy;
            if (delx >= 0 && delx < n && dely >= 0 && dely < m && v[delx][dely] != '#' && !visited[delx][dely])
            {
                path[delx][dely] = dir[i];
                q.push({delx, dely});
                visited[delx][dely] = true;
                if (end.first == delx && end.second == dely)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
        {
            break;
        }
    }
 
    if (!flag)
    {
        cout << "NO\n";
        return;
    }
 
    cout << "YES\n";
 
    map<char, pair<int, int>> mp;
    mp['U'] = {1, 0};
    mp['R'] = {0, -1};
    mp['D'] = {-1, 0};
    mp['L'] = {0, 1};
 
    string k = "";
 
    int x = end.first;
    int y = end.second;
 
    while (path[x][y] != '@')
    {
        k += path[x][y];
        int delx = mp[path[x][y]].first;
        int dely = mp[path[x][y]].second;
        x += delx;
        y += dely;
    }
 
    reverse(k.begin(), k.end());
 
    cout << k.size() << '\n';
    cout << k << '\n';
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}