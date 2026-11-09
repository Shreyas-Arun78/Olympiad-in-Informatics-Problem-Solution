#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    while (n / 5 > 0)
    {
        ans += (n / 5);
        n /= 5;
    }
    cout<<ans<<'\n';
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}