#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> p(n), a(m);
    for (auto &i : p)
        cin >> i;
    for (auto &i : a)
        cin >> i;

    sort(a.begin(), a.end());
    sort(p.begin(), p.end());

    ll i = 0, j = 0, cnt = 0;
    while (i < n && j < m)
    {
        ll mini = p[i] - k;
        ll maxi = p[i] + k;
        if(mini>a[j])
        {
            j++;
        }
        else if(maxi<a[j])
        {
            i++;
        }
        else 
        {
            i++;j++;
            cnt++;
        }
    }
    cout << cnt << '\n';
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