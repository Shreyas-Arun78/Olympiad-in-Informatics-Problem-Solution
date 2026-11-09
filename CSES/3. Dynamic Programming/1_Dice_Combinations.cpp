#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> ways(1e6 + 3);
    ways[0] = ways[1] = 1;
    ways[2] = 2;
    ways[3] = 4;
    ways[4] = 8;
    ways[5] = 16;
    ways[6] = 32;
    for(int i=7;i<=n;i++)
    {
        ways[i] = (ways[i-1]+ways[i-2]+ways[i-3]+ways[i-4]+ways[i-5]+ways[i-6])%mod;
    }
    cout<<ways[n]%mod<<'\n';
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