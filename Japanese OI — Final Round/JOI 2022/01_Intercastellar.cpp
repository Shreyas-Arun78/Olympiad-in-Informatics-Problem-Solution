#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;

    vector<ll>index, val;

    ll start = 0;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x & 1)
        {
            index.push_back(++start);
            val.push_back(x);
        }
        else
        {
            ll y = x;
            ll cnt = 0;
            while (!(y & 1))
            {
                cnt++;
                y /= 2;
            }
            index.push_back(start+1);
            val.push_back(y);
            index.push_back(start+(x/y));
            val.push_back(y);
            start += (x / y);
        }
    }


    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        ll lb = lower_bound(index.begin(),index.end(),x)-index.begin();
        cout<<val[lb]<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}