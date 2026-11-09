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
    set<ll> s;
    while (n--)
    {
        ll x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
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