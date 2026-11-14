#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    ll cnt = 0;
    while (i <= j)
    {
        if(v[i]+v[j]>x)
        {
            cnt++;
            j--;
        }
        else if(v[i]+v[j]<=x)
        {
            cnt++;
            i++;
            j--;
        }
    }
    cout<<cnt<<'\n';
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