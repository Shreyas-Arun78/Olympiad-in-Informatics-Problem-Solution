#include <bits/stdc++.h>
using namespace std;
 
void ways(int row, int n, vector<bool> &col, vector<bool> &d1, vector<bool> &d2, vector<vector<char>> &board, int &ans)
{
    if (row == n)
    {
        ans++;
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (board[row][i] != '*' &&!col[i] && !d1[n - 1 + row - i] && !d2[row + i]) 
            {
                col[i] = true;
                d1[n - 1 + row - i] = true;
                d2[row + i] = true;
                ways(row + 1, n, col, d1, d2, board, ans);
                col[i] = false;
                d1[n - 1 + row - i] = false;
                d2[row + i] = false;
            }
        }
    }
}
 
void solve()
{
    int n = 8;
    vector<vector<char>> board(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    vector<bool> col(n, false), d1(2 * n - 1, false), d2(2 * n - 1, false);
    int ans = 0;
    ways(0, n, col, d1, d2, board, ans);
    cout << ans << '\n';
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}