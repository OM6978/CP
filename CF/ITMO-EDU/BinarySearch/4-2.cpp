#include <bits/stdc++.h>
using namespace std;

int* parent;

bool good(double avg,vector<vector<pair<int,int>>> & adj,int N)
{
    double worst[N+1];
    for(int i=2;i<=N;i++)worst[i] = 1e9;
    worst[1] = 0;

    for(int u=2;u<=N;u++)
    {
        for(auto &[v,x] : adj[u])
        {
            if(worst[u] > (x-avg)+worst[v])
            {
                worst[u] = (x-avg)+worst[v];
                parent[u] = v;
            }
        }
    }

    return worst[N] <= 0;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<pair<int,int>>> adj (N+1,vector<pair<int,int>>());

    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;

        adj[v].push_back({u,c});
    }

    parent = new int[N+1];

    double l = -1,r = 100;
    while(l+1e-5<=r)
    {
        double mid = (l+r)/2;
        if(good(mid,adj,N))r = mid;
        else l = mid;
    }

    good(r,adj,N);

    vector<int> ans;
    int curr = N;

    while(curr != 1)
    {
        ans.push_back(curr);
        curr = parent[curr];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    
    cout << ans.size() - 1 << '\n';
    for(int i : ans)
    {
        cout << i << ' ';
    }
    cout << '\n';

    delete parent;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}