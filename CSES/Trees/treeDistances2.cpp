#include <bits/stdc++.h>
using namespace std;

#define int long long

void rdfs(int u,pair<int,int> pdist,int par,vector<pair<int,int>> & cdist,vector<vector<int>> & tree,vector<int> & res)
{
    res[u] = cdist[u].first + pdist.first;
    for(int v : tree[u])
    {
        if(v == par)continue;

        int cpnum = cdist[u].second - cdist[v].second;
        int cpsum = cdist[u].first - cdist[v].first - cdist[v].second;

        int pnum = pdist.second + cpnum;
        int psum = pdist.first + pdist.second;
        psum += cpsum + cpnum;

        rdfs(v,{psum,pnum},u,cdist,tree,res);
    }
}

pair<int,int> cdfs(int u,int par,vector<pair<int,int>> & cdist,vector<vector<int>> & tree)
{
    int sum = 0;
    int num = 0;

    for(int v : tree[u])
    {
        if(v == par)continue;

        auto [s,n] = cdfs(v,u,cdist,tree);
        sum += s;
        num += n;
    }
    sum += num;
    num++;

    return cdist[u] = {sum,num};
}

void solve()
{
    int N;
    cin>>N;

    vector<vector<int>> tree(N+1);
    
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
    
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<pair<int,int>> cdist(N+1,{0,0});
    vector<int> res(N+1,0);

    cdfs(1,-1,cdist,tree);
    rdfs(1,{0,0},-1,cdist,tree,res);

    for(int i=1;i<=N;i++)
    {
        cout << res[i] << ' '; 
    }
    cout << '\n';
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