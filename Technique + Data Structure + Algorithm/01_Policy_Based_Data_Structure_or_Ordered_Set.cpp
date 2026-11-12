#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
    // intializing pbds
    pbds a;
    // inserting values
    a.insert(1);
    a.insert(10);
    a.insert(2);
    a.insert(7);
    a.insert(2);

    // printing values
    for (auto &i : a)cout << i << ' ';
    cout << '\n';

    // finding k-th element
    cout << "0th element : " << *a.find_by_order(0) << '\n';
    cout << "1st element : " << *a.find_by_order(1) << '\n';
    cout << "2nd element : " << *a.find_by_order(2) << '\n';
    cout << "3rd element : " << *a.find_by_order(3) << '\n';

    cout<<'\n';

    // finding number of elements smaller than x
    cout << "Number of elements smaller than 6 : " << a.order_of_key(6) << '\n'; // 2
    cout << "Number of elements smaller than 11 : " << a.order_of_key(11) << '\n'; // 4
    cout << "Number of elements smaller than 1 : " << a.order_of_key(1) << '\n'; // 0

    cout<<'\n';

    // finding lower_bound -> first element >=x
    cout<<"Lower Bound of 6 :"<<*a.lower_bound(6)<<'\n';
    cout<<"Lower Bound of 1 :"<<*a.lower_bound(2)<<'\n';

    cout<<'\n';

    // finding upper_bound -> first element >x
    cout<<"Upper Bound of 6 :"<<*a.upper_bound(6)<<'\n';
    cout<<"Upper Bound of 1 :"<<*a.upper_bound(1)<<'\n';

    cout<<'\n';

    // remove element
    a.erase(11);
    a.erase(1);
    for(auto &i:a)cout<<i<<' ';
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}