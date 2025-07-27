#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<pair<int,int>> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i].first;
        ar[i].second = i;
    }

    sort(ar.begin(),ar.end());

    int rounds = 0,last = -1;
    for(int i=0;i<N;i++)
    {
        if(ar[i].second < last)
        {
            rounds++;
        }
        last = ar[i].second;
    }

    cout << rounds+1 << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}