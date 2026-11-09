/**
 * author : Shreyas Arun :)
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve()
{
    ll n;
    cin >> n;
    ll y = 0;
    ll ttl = n * (n + 1) / 2;
    n--;
    while (n--)
    {
        ll x;
        cin >> x;
        y += x;
    }
 
    cout << ttl - y << '\n';
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