#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
  ll n, x, y;
   cin>>n>>x>>y;
   ll ans =0;
   while(n--)
   {
      ll a ;cin>>a;
      ans+=min(y,a*x);
   }
   cout<<ans<<'\n';
   return 0;
}