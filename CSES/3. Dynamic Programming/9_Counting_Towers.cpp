#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1e6 + 2;
const ll mod = 1e9 + 7;

ll dp[maxn][2];

void cal()
{
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = (2 * dp[i - 1][1] + dp[i - 1][0]) % mod;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << (dp[n][0]+dp[n][1])%mod << '\n';
    }
    return 0;
}