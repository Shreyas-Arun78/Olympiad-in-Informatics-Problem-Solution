#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;

void solve()
{
   ll n, m;
   cin >> n >> m;
   vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, inf));
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         if (i == j)
         {
            dp[i][j] = 0;
            continue;
         }
         for (int v = 1; v < j; v++)
         {
            dp[i][j] = min(dp[i][j], dp[i][j - v] + dp[i][v] + 1);
         }
         for (int h = 1; h < i; h++)
         {
            dp[i][j] = min(dp[i][j], dp[h][j] + dp[i - h][j] + 1);
         }
      }
   }
   cout << dp[n][m] << '\n';
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t = 1;
   // cin>>t;
   while (t--)
   {
      solve();
   }
   return 0;
}