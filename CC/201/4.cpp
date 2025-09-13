#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,M;
    cin>>N>>M;

    string res;

    if(M==0)
    {
        for(int i=0;i<2*N-3;i++)
        {
            res.push_back('<');
        }
        res.push_back('=');
        res.push_back('<');
    }
    else if(N==0)
    {
        for(int i=0;i<M-2;i++)
        {
            res.push_back('>');
            res.push_back('<');
        }
        res.push_back('>');
        res.push_back('=');
        res.push_back('>');
    }
    else
    {
        for(int i=0;i<2*N-1;i++)
        {
            res.push_back('<');
        }
    
        for(int i=0;i<M;i++)
        {
            res.push_back('<');
            res.push_back('>');
        }
    }

    cout << res << '\n';
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