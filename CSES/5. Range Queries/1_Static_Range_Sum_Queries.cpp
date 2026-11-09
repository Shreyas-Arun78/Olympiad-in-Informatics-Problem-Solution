#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << v[b] - v[a - 1] << '\n';
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}