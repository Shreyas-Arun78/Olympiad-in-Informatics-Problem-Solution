#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<int>pos(n+1,1);
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        pos[x] = i+1;
    }
    for(int i=1;i<n;i++)pos[0]+=(pos[i]>pos[i+1]);
    cout<<pos[0]<<'\n';
}