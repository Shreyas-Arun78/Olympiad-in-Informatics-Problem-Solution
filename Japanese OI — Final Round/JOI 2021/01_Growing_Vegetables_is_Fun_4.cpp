#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
   ll n;cin>>n;
   vector<ll>v(n);
   for(auto &i:v)cin>>i;
   vector<ll>pref(n,0),suf(n,0);
   for(int i=1;i<n;i++)
   {    
        ll need = max(0LL, v[i-1]-v[i]+1);
        pref[i] = pref[i-1]+need;
   }
   for(int i = n-2;i>=0;i--)
   {
    ll need = max(0LL,v[i+1]-v[i]+1);
    suf[i] = need+suf[i+1];
   }
   ll ans = LLONG_MAX;
   for(int i =0;i<n;i++)
   {
    ans = min(ans,max(pref[i],suf[i]));
   }
   cout<<ans<<'\n';
}


int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t=1;
   //cin>>t;
   while(t--){
   solve();}
   return 0;
}