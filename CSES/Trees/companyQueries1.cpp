#include <bits/stdc++.h>
using namespace std;

void dfs(int u,int par,vector<int> & parents,unordered_map<int,vector<pair<int,int>>> & queries,vector<vector<int>> & tree,vector<int> & res)
{
    auto uqs = queries[u];
    int psz = parents.size();
    for(auto [q,rin] : uqs)
    {
        if(q > psz)res[rin] = -1;
        else
        {
            res[rin] = parents[psz - q];
        }
    }

    // cout << u << ' ' << psz << ' ' << uqs.size() << '\n';

    for(int v : tree[u])
    {
        if(v == par)continue;

        parents.push_back(u);
        dfs(v,u,parents,queries,tree,res);
        parents.pop_back();
    }
}

void solve()
{
    int N,Q;
    cin>>N>>Q;

    vector<vector<int>> tree(N+1);
    
    for(int i=2;i<=N;i++)
    {
        int p;
        cin>>p;
    
        tree[i].push_back(p);
        tree[p].push_back(i);
    }

    vector<int> res(Q);
    unordered_map<int,vector<pair<int,int>>> queries;

    for(int i=0;i<Q;i++)
    {
        int u,rank;
        cin>>u>>rank;

        queries[u].push_back({rank,i});
    }

    vector<int> parents;
    dfs(1,-1,parents,queries,tree,res);

    for(int a : res)cout << a << '\n';
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