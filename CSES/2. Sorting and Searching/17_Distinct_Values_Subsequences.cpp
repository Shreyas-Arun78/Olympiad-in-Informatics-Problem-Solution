#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
void solve()
{
    ll n;
    cin >> n;
    map<ll, ll> mp;
    while (n--)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    ll sum =1;
    for(auto &[key,value]:mp)
    {
        sum = (sum*(value+1))%mod;
    }
    cout<<sum-1<<'\n';
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