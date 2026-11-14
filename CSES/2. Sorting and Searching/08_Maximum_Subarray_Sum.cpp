#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, ans = INT_MIN, sum=0;
    cin >> n;
    while (n--)
    {
        long long x; cin >> x;
        sum += x;
        ans = max(ans, sum);
        if (sum < 0) {sum = 0; continue;}
    }
    cout << ans << '\n';
}