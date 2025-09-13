#include <bits/stdc++.h>
using namespace std;

#define int long long

bool good(int xtra,int curr,int N,int K)
{
    return curr + xtra <= K;
}

void solve()
{
    int N,K;
    cin>>N>>K;

    vector<int> base3;
    while(N > 0)
    {
        base3.push_back(N%3LL);
        N/=3LL;
    }

    int ldeals = accumulate(base3.begin(),base3.end(),0LL);

    int bsz = base3.size();
    for(int i=bsz-2;i>=0;i--)
    {
        int odeals = base3[i+1];

        int l = 0,r = odeals*2+1;
        while(l + 1 < r)
        {
            int mid = (l+r)>>1LL;
            if(good(mid,ldeals,N,K))l = mid;
            else r = mid;
        }
        
        int xtra = l/2;

        ldeals = ldeals + xtra*2;
        base3[i+1] -= xtra;
        base3[i] += xtra*3;
    }

    if(ldeals > K)
    {
        cout << -1 << '\n';
        return;
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