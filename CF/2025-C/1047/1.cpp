#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int K,X;
    cin>>K>>X;

    while(K--)
    {
        if(X&1)
        {
            X <<= 1;
        }
        else if((X - 1)%3 == 0)
        {
            X = (X-1)/3;
        }
        else
        {
            X <<= 1;
        }
    }

    cout << X << '\n';
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