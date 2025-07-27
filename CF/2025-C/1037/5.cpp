#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<int> br(N);
    for(int i=0;i<N;i++)
    {
        cin>>br[i];
    }

    vector<int> gar;
    for(int i=0;i<N;i++)
    {
        int lcm = ar[i]*br[i] / __gcd(ar[i],br[i]);
        gar.push_back(lcm);
    }

    int pref = 0,suff = 0;
    for(int i=0;i<N;i++)
    {
        pref = __gcd(pref,gar[i]);
        suff = __gcd(suff,gar[N-i-1]);
        if(pref != ar[i] || suff != br[N-i-1])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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