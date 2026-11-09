#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
 
ll n, m;
 
void dfs(ll row, ll col, vector<vector<char>> &v, vector<vector<bool>> &visited)
{
    visited[row][col] = true;
    for (auto &[x, y] : dir)
    {
        ll dx = row + x;
        ll dy = col + y;
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && !visited[dx][dy] && v[dx][dy] != '#')
        {
            dfs(dx, dy, v, visited);
        }
    }
}
 
void solve()
{
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (auto &i : v)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }
 
    vector<vector<bool>> visited(n, vector<bool>(m, false));
 
    ll cc = 0;
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && v[i][j] == '.')
            {
                cc++;
                dfs(i, j, v, visited);
            }
        }
    }
    cout << cc << '\n';
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}