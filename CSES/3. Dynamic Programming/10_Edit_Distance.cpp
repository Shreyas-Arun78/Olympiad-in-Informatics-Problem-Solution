#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
   string a, b;
   cin >> a >> b;
   ll n = a.size(), m = b.size();
   vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
   for (int i = 0; i <= m; i++)
      dp[0][i] = i;
   for (int i = 1; i <= n; i++)
      dp[i][0] = i;

   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         if (a[i - 1] == b[j - 1])
         {
            dp[i][j] = dp[i - 1][j - 1];
         }
         else
         {
            dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1],dp[i-1][j-1]});
         }
      }
   }
   cout<<dp[n][m]<<'\n';
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