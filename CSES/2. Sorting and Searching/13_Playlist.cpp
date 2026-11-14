#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;
    set<ll> s;
    ll last_removed = 0, ans = 0LL,cur = 0LL;
    for (int i = 0; i < n; i++)
    {
        if (s.find(a[i]) == s.end())
        {
            s.insert(a[i]);
            cur++;
        }
        else
        {
            while(s.find(a[i])!=s.end())
            {
                s.erase(s.find(a[last_removed++]));
                cur--;
            }
            cur++;
            s.insert(a[i]);
        }
        ans = max(ans,cur);
    }
    cout<<ans<<'\n';
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