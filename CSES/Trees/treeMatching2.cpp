#include <bits/stdc++.h>
using namespace std;
 
pair<int,bool> dfs(int u,int par,vector<vector<int>> & tree)
{
    int ans = 0;
    bool done = false;
    for(int v : tree[u])
    {
        if(v!=par)
        {
            auto [pairs,sel] = dfs(v,u,tree);
            ans += pairs;
            if(!sel)
            {
                if(!done)
                {
                    ans++;
                    done = true;
                }
            }
        }
    }

    return {ans,done};
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

    cout << dfs(1,-1,tree).first << '\n'; 
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