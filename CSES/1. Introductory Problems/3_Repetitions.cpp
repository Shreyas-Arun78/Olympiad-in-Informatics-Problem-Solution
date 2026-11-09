/**
 * author : Shreyas Arun :)
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve()
{
    string s;
    cin >> s;
    ll ans = 1;
    ll cnt = 1;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            cnt++;
            ans = max(ans, cnt);
        }
        else
        {
            cnt = 1;
        }
    }
    cout << ans << '\n';
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