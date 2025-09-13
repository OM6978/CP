#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    vector<int> base3;
    while(N > 0)
    {
        base3.push_back(N%3LL);
        N/=3LL;
    }

    int dealmx = 1,x = -1;
    int coins = 0;
    for(int i=0;i<base3.size();i++)
    {
        dealmx *=3;
        x++;
        int t2 = (dealmx/9LL)*x;

        coins += (dealmx + t2)*base3[i];
    }

    cout << coins << '\n';
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