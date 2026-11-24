#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, int>> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> b[i].first;
        a[i].second = b[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        ans[a[i].second] += (n - i - 1);
        ans[b[i].second] += i;
    }
    for (auto &i : ans)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}