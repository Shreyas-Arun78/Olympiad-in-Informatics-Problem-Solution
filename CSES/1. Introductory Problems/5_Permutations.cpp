#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
void solve()
{
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<'\n';
        return;
    }
    if(n<=3)
    {
        cout<<"NO SOLUTION\n";
        return;
    }
    for(int i = 2;i<=n;i+=2)
    {
        cout<<i<<' ';
    }
    for(int i = 1;i<=n;i+=2)
    {
        cout<<i<<' ';
    }
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}