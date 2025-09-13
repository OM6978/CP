#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    int osum = 0;
    int esum = 0;

    int lposvalScore[2][2];
    int rposvalScore[2][2];

    fill(&lposvalScore[0][0], &lposvalScore[0][0] + 2*2, 1000000000000000LL);
    fill(&rposvalScore[0][0], &rposvalScore[0][0] + 2*2, 0LL);

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];

        if(i&1)
        {
            esum +=ar[i];
        }
        else
        {
            osum += ar[i];
        }

        lposvalScore[i&1][1] = min(lposvalScore[i&1][1],2LL*ar[i] + i + 1LL);
        lposvalScore[i&1][0] = min(lposvalScore[i&1][0],2LL*ar[i] - i - 1LL);

        rposvalScore[i&1][1] = max(rposvalScore[i&1][1],2LL*ar[i] + i + 1LL);
        rposvalScore[i&1][0] = max(rposvalScore[i&1][0],2LL*ar[i] - i - 1LL);
    }

    int addon = N-2+(N&1);
    addon = max(max(rposvalScore[1][1] - lposvalScore[0][1],rposvalScore[1][0] - lposvalScore[0][0]),addon);

    cout << osum - esum + addon << '\n';
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