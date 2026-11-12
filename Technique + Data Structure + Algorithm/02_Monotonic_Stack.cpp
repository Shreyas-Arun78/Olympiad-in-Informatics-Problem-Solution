// problem link - https://cses.fi/problemset/task/1645/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> v(n);

    for (auto &i : v)
        cin >> i;

    stack<pair<ll,ll>> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top().first >= v[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            cout<<0<<' ';
        }
        else
        {
            cout<<s.top().second<<' ';
        }
        s.push({v[i],i+1});
    }
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