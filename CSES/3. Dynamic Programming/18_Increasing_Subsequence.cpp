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
    vector<ll> s;
    s.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        ll lb = lower_bound(s.begin(), s.end(), v[i]) - s.begin();
        if (lb >= s.size())
        {
            s.push_back(v[i]);
            continue;
        }
        else
        {
            s[lb] = v[i];
        }
    }
    cout << s.size() << '\n';
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