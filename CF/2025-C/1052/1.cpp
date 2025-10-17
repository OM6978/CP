#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    unordered_map<int,int> arFreq;

    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        arFreq[ar[i]]++;
    }

    int most = 0;
    for(int freq=1;freq<=N;freq++)
    {
        int subsz = 0;
        for(auto [x,f] : arFreq)
        {
            if(f >= freq)
            {
                subsz += freq;
            }
        }

        most = max(subsz,most);
    }

    cout << most << "\n";
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