#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> cycleID; 

vector<int> height;
vector<int> cycHead;
vector<int> nroot;

int dfsCyc(int u,vector<int> & graph,vector<int> & vis,vector<int> & svis)
{
    if(vis[u])
    {
        if(cycleID[u].first == 0)
        {
            cycleID[u] = {u,0};
            return u;
        }
        else
        {
            return -1;
        }
    }

    if(svis[u])return -1;

    vis[u] = 1;
    svis[u] = 1;

    int res = dfsCyc(graph[u],graph,vis,svis);

    vis[u] = 0;

    if(res != -1)
    {
        cycleID[u] = cycleID[res];
        cycleID[u].second++;

        if(cycleID[u].first == u)return -1;

        return u;
    }

    return -1;
}

void detectCycles(vector<int> & graph)
{
    int N = graph.size() - 1;

    vector<int> vis(N+1,0);
    vector<int> vis2(N+1,0);

    for(int u=1;u<=N;u++)
    {
        if(vis2[u] == 0)
            dfsCyc(u,graph,vis,vis2);
    }
}

void hdDfs(int u,int par,vector<vector<int>> & tree)
{
    nroot[u] = nroot[par];
    height[u] = height[par] + 1;

    for(int v : tree[u])
    {
        if(v == par)continue;

        hdDfs(v,u,tree);
    }
}

void solve()
{
    int N;
    cin>>N;

    cycleID.assign(N+1,{0,0});
    height.assign(N+1,-1);
    cycHead.assign(N+1,0);
    nroot.assign(N+1,0);

    vector<int> graph(N+1);
    for(int u=1;u<=N;u++)
    {
        int v;
        cin>>v;

        graph[u] = v;
    }

    detectCycles(graph);

    vector<int> roots;
    for(int u=1;u<=N;u++)
    {
        if(cycleID[u].first == 0)continue;

        auto [id,order] = cycleID[u];

        if(id == u)
        {
            roots.push_back(u);
        }

        // cout << u << ' ' << id << ' ' << order << '\n';
    }

    // for(int root : roots)
    //     cout << root << ' ';

    // for(int u=1;u<=N;u++)
    // {
    //     cout << u << '\n';
    //     for(int v : tree[u])
    //     {
    //         cout << v << ' ';
    //     }
    //     cout << '\n';
    //     cout << '\n';
    // }
    // cout << '\n';

    vector<vector<int>> tree(N+1);

    for(int u=1;u<=N;u++)
    {
        if(cycleID[u].first != 0)
        {
            continue;
        }

        int v = graph[u];

        if(cycleID[v].first != 0)
        {
            cycHead[u] = v;
            v = cycleID[v].first;
        }

        tree[v].push_back(u);
        tree[u].push_back(v);
    }

    // for(int u=1;u<=N;u++)
    // {
    //     cout << u << '\n';
    //     for(int v : tree[u])
    //     {
    //         cout << v << ' ';
    //     }
    //     cout << '\n';
    //     cout << '\n';
    // }

    for(int root : roots)
    {
        nroot[0] = root;
        hdDfs(root,0,tree);

        // cout << nroot[root] << ' ';
    }
    // cout << '\n';

    for(int u=1;u<=N;u++)
    {
        if(cycleID[u].first != 0)
        {
            int cH = cycleID[u].first;
            cout << cycleID[cH].second << ' ';
            continue;
        }

        // cout << u << ' ' << height[u] << ' ' << nroot[u] << '\n';

        int r = nroot[u];
        int ures = height[u];

        ures += cycleID[r].second;
        cout << ures << ' ';
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