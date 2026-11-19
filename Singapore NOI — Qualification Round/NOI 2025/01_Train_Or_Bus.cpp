#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   ll n;
   cin>>n;
   vector<ll>a(n),b(n);
   for(auto &i:a)cin>>i;
   for(auto &i:b)cin>>i;
   ll ans =0;
   for(int i=0;i<n;i++)ans+=min(a[i],b[i]);
   cout<<ans<<'\n';
   return 0;
}