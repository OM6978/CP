#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    pair<int,int> p1,p2,p3;
    cin>>p1.first>>p1.second;
    cin>>p2.first>>p2.second;
    cin>>p3.first>>p3.second;

    int slopen = (p2.second - p1.second);
    int sloped = (p2.first - p1.first);

    int val = slopen * (p3.first - p1.first) - sloped*(p3.second - p1.second);

    if(val < 0)cout << "LEFT\n";
    else if(val > 0)cout << "RIGHT\n";
    else cout << "TOUCH\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}