#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;

    string ans;
    for(int c : s)
    {
        if(c == 'T')ans.push_back(c);
    }
    for(int c : s)
    {
        if(c!='T')ans.push_back(c);
    }

    cout << ans << '\n';
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