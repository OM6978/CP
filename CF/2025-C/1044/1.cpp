#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    unordered_set<int> arset;

    vector<int> ar(N);
    bool found = 0;
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        
        if(found == 0 && arset.find(ar[i]) != arset.end())
        {
            cout << "YES\n";
            found = 1;
        }

        arset.insert(ar[i]);
    }

    if(found==0)cout << "NO\n";
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