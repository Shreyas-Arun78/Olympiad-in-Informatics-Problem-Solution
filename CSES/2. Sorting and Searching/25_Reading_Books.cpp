#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    ll sum = 0,maxi  =0;
    while(n--)
    {
        ll x;cin>>x;
        sum+=x;maxi = max(x,maxi);
    }
    cout<<max(2*maxi,sum)<<'\n';
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