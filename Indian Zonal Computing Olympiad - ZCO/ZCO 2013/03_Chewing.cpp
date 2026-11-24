#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > k)
            break;
        ll ub = upper_bound(v.begin(), v.end(), k - v[i]-1) - v.begin();
        if(ub-1<=i)continue;

        ans += (ub <= 0 ? 0 : ub - i-1);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}