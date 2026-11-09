#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll ans = LLONG_MAX;
 
void diff(ll i, ll sum, vector<ll> &v, ll ttl_sum)
{
    if (i >= v.size())
    {
        ll s1 = sum;
        ll s2 = ttl_sum - s1;
        ans = min(ans, llabs(s2 - s1));
        return ;
    }
    diff(i + 1, sum, v, ttl_sum);
    diff(i + 1, sum + v[i], v, ttl_sum);
}
 
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    ll ttl_sum = accumulate(v.begin(), v.end(), (ll)0);
    diff((ll)0, (ll)0, v, ttl_sum);
    cout << ans << '\n';
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}