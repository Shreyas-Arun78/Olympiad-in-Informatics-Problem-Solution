/**
 *     author : Shreyas Arun :)
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, h;
    cin >> n >> h;
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    ll i = 0, cal = 0;
    while (true)
    {
        ll x;
        cin >> x;
        if (x == 1 && i > 0)
        {
            i--;
        }
        else if (x == 2 && i < (n - 1))
        {
            i++;
        }
        else if (x == 3 && !cal && v[i])
        {
            v[i]--;
            cal = 1;
        }
        else if (x == 4 && cal && v[i] < h)
        {
            v[i]++;
            cal = 0;
        }
        else if (!x)
        {
            break;
        }
    }
    for (auto &i : v)
    {
        cout << i << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}