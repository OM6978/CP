#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,X;
    cin>>N>>X;

    vector<pair<int,int>> ar(N);
    for(int i=0;i<N;i++)
    {
        int val;
        cin>>val;

        ar[i] = {val,i};
    }

    sort(ar.begin(),ar.end());

    int l = 0,r = N-1;
    while(l<r)
    {
        if(ar[l].first + ar[r].first == X)
        {
            cout << ar[l].second + 1 << ' ' << ar[r].second + 1 << '\n';
            return;
        }
        else if(ar[l].first + ar[r].first > X)
        {
            r--;
        }
        else l++;
    }

    cout << "IMPOSSIBLE\n";
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