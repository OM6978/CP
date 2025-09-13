#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 998244353;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int sccs(int u,vector<vector<int>> & graph,vector<int> & vis)
{
    if(vis[u])return 0;

    vis[u] = 1;

    int res = 0;
    for(int v : graph[u])
    {
        res = 1 + sccs(v,graph,vis);
    }

    return res;
}

void makeGraph(int i,vector<int> & ar,vector<vector<int>> & arGraph,vector<int> & vis)
{
    if(vis[i])return;

    vis[i] = 1;

    if(ar[i]!=i)
    {
        arGraph[i].push_back(ar[i]);
        makeGraph(ar[i],ar,arGraph,vis);
    }
}

void solve()
{
    int N;
    cin>>N;

    vector<vector<int>> arGraph(N+1,vector<int> ());

    vector<int> ar(N+1);
    for(int i=1;i<=N;i++)
    {
        cin>>ar[i];
    }

    vector<int> vis(N+1,0);
    for(int i=1;i<=N;i++)
    {
        makeGraph(i,ar,arGraph,vis);
    }

    vis.assign(N+1,0);

    unordered_map<int,int,custom_hash> swapHash;
    for(int i=1;i<=N;i++)
    {
        if(vis[i]==0)
        {
            int swapsccn = sccs(i,arGraph,vis);
            if(swapsccn)
            {
                swapHash[swapsccn]++;
            }
        }
    }

    vector<pair<int,int>> swaps;
    for(auto p : swapHash)
    {
        swaps.push_back(p);
    }

    sort(swaps.begin(),swaps.end());

    int replacements = 0;
    for(int i=1;i<=N;i++)
    {
        if(ar[i] != i)replacements++;
    }

    cout << swaps.size() << ' ' << replacements << '\n';

    int cost = 0;
    for(int A=1;A<=N;A++)
    {
        
    }

    cout << cost << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}