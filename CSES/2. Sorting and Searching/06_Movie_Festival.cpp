#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
   ll n;cin>>n;
   vector<pair<ll,ll>>v(n);
   for(int i =0;i<n;i++)
   {
        ll a, b;cin>>a>>b;
        v[i] = {b,a};
   }
   sort(v.begin(),v.end());
   ll cnt =1;
   pair<ll,ll>last = v[0];
   for(int i = 1;i<n;i++)
   {
        auto [f, s] = last;
        if(f<=v[i].second)
        {
            cnt++;
            last = v[i];
        }
   }
   cout<<cnt<<'\n';
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