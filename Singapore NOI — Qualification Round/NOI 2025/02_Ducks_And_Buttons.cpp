#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
   ll n, d;
   cin >> n >> d;
   vector<ll> v(n);
   for (auto &i : v)
      cin >> i;
   ll maxi = 0, ans = 0;
   for (int i = n - 1; i > 0; i--)
   {
      maxi = max(maxi, v[i]);
      ans += maxi;
   }
   cout << (d < v[0] ? ans + v[0] - d : ans) << '\n';
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   solve();
   return 0;
}