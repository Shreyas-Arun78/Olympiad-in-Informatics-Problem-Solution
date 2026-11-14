#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    if (((n * (n + 1)) / 2) & 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    ll x = (n * (n + 1)) / 4;
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j >= i; j--)
            dp[j] = (dp[j] + dp[j - i]) % mod;
    }
    // cout << (dp[x] / 2) % mod << '\n';
    cout << dp[x] * 500000004 % mod << '\n';
    return 0;
}