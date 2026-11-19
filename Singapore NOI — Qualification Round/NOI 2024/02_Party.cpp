#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   ll n;cin>>n;
   vector<ll>v(n);
   for(auto &i:v)cin>>i;
   sort(v.rbegin(),v.rend());
   ll ans = 0;
   for(int i=0;i<((n/2)+(n&1));i++)
   {
      if(v[i]<0)break;
      ans+=v[i];
   }
   cout<<ans<<'\n';
   return 0;
}