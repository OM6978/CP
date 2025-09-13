#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,Q;
    cin>>N>>Q;

    unordered_map<int,int> clusterHash;

    vector<int> cycleInd;

    vector<vector<int>> clusters;
    vector<unordered_map<int,int>> nodeHash;

    vector<int> indeg(N+1,0);

    vector<int> nextNode(N+1,0);

    for(int i=1;i<=N;i++)
    {
        cin>>nextNode[i];
        indeg[nextNode[i]]++;
    }

    vector<bool> vis(N+1,0);

    auto traverse = [&](int u,auto && traverse) -> void
    {
        int c = clusterHash[u];
        int v = nextNode[u];

        if(vis[v])
        {
            cycleInd[c] = nodeHash[c][v];
            return;
        }

        clusterHash[v] = c;
        clusters[c].push_back(v);
        nodeHash[c][v] = clusters[c].size();

        vis[v] = true;
        traverse(v,traverse);
    };

    for(int i=1;i<=N;i++)
    {
        if(!vis[i] && indeg[i] == 0)
        {
            cycleInd.push_back(0);

            clusterHash[i] = clusters.size();

            clusters.push_back({0,i});
            nodeHash.push_back({});

            nodeHash.back()[i] = 1;
            vis[i] = true;

            traverse(i,traverse);
        }
    }

    for(int i=1;i<=N;i++)
    {
        if(!vis[i])
        {
            cycleInd.push_back(0);
            
            clusterHash[i] = clusters.size();

            clusters.push_back({0,i});
            nodeHash.push_back({});

            nodeHash.back()[i] = 1;
            vis[i] = true;

            traverse(i,traverse);
        }
    }

    for(auto cluster : clusters)
    {
        for(int node : cluster)
        {
            cout << node << ' ';
        }
        cout << '\n';
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