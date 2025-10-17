#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 1;

vector<pair<int,int>> cycleID; 

vector<int> height;
vector<int> depth;

/* --- HLD --- */ 

vector<int> p;
vector<int> head;
vector<int> hChild;

/* ----------- */

vector<int> cycHead;

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
    height[u] = height[par] + 1;

    for(int v : tree[u])
    {
        if(v == par)continue;

        hdDfs(v,u,tree);
        if(depth[v] + 1 > depth[u])
        {
            depth[u] = depth[v] + 1;
            hChild[u] = v;
        }
    }
}

void hldDfs(int u,int par,vector<vector<int>> & tree)
{
    for(int v : tree[u])
    {
        if(v == par)continue;

        if(v == hChild[u])
        {
            p[v] = p[u];
            head[v] = head[u];
        }
        else
        {
            p[v] = u;
            head[v] = v;
        }

        if(cycleID[u].first == 0)
            cycHead[v] = cycHead[u];

        hldDfs(v,u,tree);
    }
}

void solve()
{
    int N,Q;
    cin>>N>>Q;

    cycleID.assign(N+1,{0,0});
    p.assign(N+1,0);
    head.assign(N+1,0);
    hChild.assign(N+1,0);
    depth.assign(N+1,0);
    height.assign(N+1,0);
    cycHead.assign(N+1,0);

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
            head[u] = u;
            p[u] = u;
        }

        // cout << u << ' ' << id << ' ' << order << '\n';
    }

    // for(int root : roots)
    //     cout << root << ' ';

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
        hdDfs(root,0,tree);

        hldDfs(root,0,tree);
        // cout << p[root] << ' ';
    }
    // cout << '\n';

    // for(int u=1;u<=N;u++)
    // {
    //     cout << p[u] << ' ';
    // }
    // cout << '\n';

    // for(int u=1;u<=N;u++)
    // {
    //     cout << cycHead[u] << ' ';
    // }
    // cout << '\n';

    for(int i=0;i<Q;i++)
    {
        int a,b;
        cin>>a>>b;

        int ta = a,tb = b;
        if(cycleID[ta].first != 0)ta = cycleID[ta].first;
        if(cycleID[tb].first != 0)tb = cycleID[tb].first;

        int dist = 0;

        int cH = cycHead[ta];
        bool pathExists = true;

        while(head[ta] != head[tb])
        {
            if(p[ta] == ta || height[p[ta]] < height[tb])
            {
                pathExists = false;
                break;
            }

            cH = cycHead[ta];
            dist += height[ta] - height[p[ta]];
            
            ta = p[ta];
        }

        // cout << pathExists << '\n';
        // cout << height[ta] << ' ' << height[tb] << '\n';

        if(!pathExists || height[ta] < height[tb] || head[ta] != head[tb])
        {
            cout << -1 << '\n';

            continue;
        }

        dist += height[ta] - height[tb];

        if(cycleID[tb].first != 0)
        {
            int c1 = b;
            int c2 = (cH != 0)?cH : a;

            // cout << c1 << ' ' << c2 << '\n';

            int cid = cycleID[c1].first;

            dist += cycleID[c2].second - cycleID[c1].second;

            if(cycleID[c2].second < cycleID[c1].second)
            {
                dist += cycleID[cid].second;
            }
        }

        cout << dist << '\n';
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input-CSES.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}