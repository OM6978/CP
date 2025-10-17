#include <bits/stdc++.h>
using namespace std;

vector<int> disColors;
vector<int> subtreeSz;
vector<int> numChanges;

unordered_map<int,vector<int>> colorOverlaps;

void dfs(int u,int par,vector<vector<int>> & tree,vector<int> & colors)
{
    subtreeSz[u]++;

    auto & v = colorOverlaps[colors[u]];
    if(v.size())
    {
        int p = v.back();

        cout << u << ' ' << p << '\n';
        
        numChanges[p]++;
    }

    v.push_back(u);

    for(int v : tree[u])
    {
        if(v == par)continue;

        dfs(v,u,tree,colors);
        subtreeSz[u] += subtreeSz[v];
        numChanges[u] += numChanges[v];
    }

    disColors[u] = subtreeSz[u] - numChanges[u];

    v.pop_back();

    if(v.size())
    {
        int p = v.back();
        numChanges[p] += numChanges[u];
    }
}

void solve()
{
    int N;
    cin>>N;

    disColors.assign(N+1,0);
    subtreeSz.assign(N+1,0);
    numChanges.assign(N+1,0);

    vector<int> colors(N+1);
    for(int u=1;u<=N;u++)
    {
        cin>>colors[u];
    }

    vector<vector<int>> tree(N+1);
    
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
    
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1,0,tree,colors);

    for(int u=1;u<=N;u++)
    {
        cout << numChanges[u] << ' ';
    }
    cout << '\n';

    for(int u=1;u<=N;u++)
    {
        cout << subtreeSz[u] << ' ';
    }
    cout << '\n';

    for(int u=1;u<=N;u++)
    {
        cout << disColors[u] << ' ';
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