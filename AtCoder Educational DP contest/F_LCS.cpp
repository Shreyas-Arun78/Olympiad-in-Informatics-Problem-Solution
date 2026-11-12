#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string a, b;
    cin >> a >> b;
    ll n = a.size(), m = b.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    ll x= dp[n][m];
    vector<char>ans;
    int i= n, j = m;
    while(i && j)
    {
        if(a[i-1]==b[j-1])
        {
            ans.push_back(a[i-1]);
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
        if(ans.size()==x)
        {
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto &i:ans)cout<<i;
    return;
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