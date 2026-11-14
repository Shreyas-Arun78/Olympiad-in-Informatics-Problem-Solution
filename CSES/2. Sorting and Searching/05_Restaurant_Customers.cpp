#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> v;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, 0});
        v.push_back({b, 1});
    }

    sort(v.begin(),v.end());

    ll x= v.size();
    ll sum = 0, cnt =0;
    for(int i=0;i<x;i++)
    {
        cnt+=(v[i].second?-1:1);
        sum = max(sum,cnt);
    }
    cout<<sum<<'\n';

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