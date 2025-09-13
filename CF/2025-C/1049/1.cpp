#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    string s;
    cin>>s;

    auto ss = s;
    sort(ss.begin(),ss.end());
    
    int diff = 0;
    for(int i=0;i<N;i++)
    {
        diff += (s[i] != ss[i]);
    }

    cout << (diff+1)/2 << '\n';
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