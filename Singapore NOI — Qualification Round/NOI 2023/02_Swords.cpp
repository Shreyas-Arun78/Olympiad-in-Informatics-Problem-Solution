#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
   ll n;
   cin >> n;
   vector<pair<ll, ll>> v(n);
   for (auto &i:v)
   {
      cin >> i.first >> i.second;
   }
   sort(v.rbegin(),v.rend());
   ll cnt = 0;
   ll maxi = v[0].second;
   for (int i = 1; i < n; i++)
   {
      if (v[i].second <= maxi)
      {
         cnt++;
      }
      else if (v[i].second > maxi)
      {
         maxi = v[i].second;
      }
   }
   cout << n - cnt << '\n';
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   solve();
   return 0;
}