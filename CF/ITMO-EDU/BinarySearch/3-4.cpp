#include <bits/stdc++.h>
using namespace std;

int* parent;

bool good(int num,vector<vector<pair<int,int>>> & adj,int N,int D,bool* vis)
{
    queue<int> q;
    q.push(N);

    int selected = 0;
    while(q.size())
    {
        if(selected > D)return false;

        int cnt = q.size();
        while(cnt--)
        {
            int u = q.front();
            if(u == 1)return true;

            for(auto &[v,x] : adj[u])
            {
                if(!vis[v] && x<=num)
                {
                    parent[v] = u;
                    q.push(v);
                    vis[v]=1;
                }
            }

            q.pop();
        }

        selected++;
    }
    
    return false;
}

void solve()
{
    int N,M,D;
    cin>>N>>M>>D;

    vector<vector<pair<int,int>>> adj (N+1,vector<pair<int,int>>());

    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;

        adj[v].push_back({u,c});
    }

    bool vis[N+1];

    int l = -1,r = 1e9 + 1;
    parent = new int[N+1];

    while(l+1<r)
    {
        for(int i=1;i<=N;i++)vis[i] = false;

        int mid = (l+r)/2;
        if(good(mid,adj,N,D,vis))r = mid;
        else l = mid;
    }

    if(r == 1e9+1){cout << -1 << '\n';return;}

    for(int i=1;i<=N;i++)vis[i] = 0;
    good(r,adj,N,D,vis);

    vector<int> ans;
    int curr = 1;
    while(parent[curr]!=N)curr = parent[curr],ans.push_back(curr);
    delete parent;

    cout << ans.size() + 1 << '\n' << 1 << ' ';
    for(int a : ans)cout << a << ' ';
    cout << N << '\n';
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