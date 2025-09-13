#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,s;
    cin>>N>>s;

    int sum = 0;
    int ones = 0;
    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
        ones += (ar[i]==1);
    }

    
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