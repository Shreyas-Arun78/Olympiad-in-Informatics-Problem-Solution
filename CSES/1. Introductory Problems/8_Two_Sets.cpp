#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
void solve()
{
    ll n;
    cin >> n;
    ll sum = (n * (n + 1));
    if (((sum >> 1) & 1) || n < 3)
    {
        cout << "NO\n";
        return;
    }
    sum >>= 2;
    vector<bool> v(n + 1, false);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sum <= n)
        {
            v[sum] = true;
            cnt++;
            break;
        }
        if (((sum & 1) && !(i & 1)) || (!(sum & 1) && (i & 1)))
        {
            sum -= i;
            cnt++;
            v[i] = true;
        }
    }
    
    cout << "YES\n"
         << cnt << '\n';
 
    for (int i = 1; i <= n; i++)
        if (v[i])
            cout << i << ' ';
 
    cout << '\n'
         << n - cnt << '\n';
 
    for (int i = 1; i <= n; i++)
        if (!v[i])
            cout << i << ' ';
 
    cout << '\n';
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}