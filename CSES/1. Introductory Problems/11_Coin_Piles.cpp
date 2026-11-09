#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define fastio()                 \
    ;                            \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr)
 
void solve()
{
    ll a, b;
    cin >> a >> b;
    if (((a + b) % 3 == 0) && ((min(a, b) * 2) >= (max(a, b))))
        cout << "YES\n";
    else
        cout << "NO\n";
}
 
int main()
{
    fastio();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}