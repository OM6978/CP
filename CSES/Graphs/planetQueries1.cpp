#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 1;
const int logK = 32;

int dests[maxN][logK];

void solve()
{
    int N,Q;
    cin>>N>>Q;

    for(int i=1;i<=N;i++)
    {
        int tdest;
        cin>>tdest;
        dests[i][1] = tdest;
    }

    for(int pk=2;pk<logK;pk++)
    {
        for(int i=1;i<=N;i++)
        {
            dests[i][pk] = dests[dests[i][pk-1]][pk-1];
        }
    }

    for(int i=0;i<Q;i++)
    {
        int u,k;
        cin>>u>>k;

        for(int p=30;p>=0;p--)
        {
            int parry = (1<<p);
            if(parry&k)
            {
                u = dests[u][p+1];
            }
        }

        cout << u << '\n';
    }
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