#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;

struct Comp
{
    const vector<long long>& cost;

    Comp(const vector<long long>& c) : cost(c) {}

    bool operator()(int v1, int v2) const
    {
        if(cost[v1] != cost[v2])
            return cost[v1] < cost[v2];

        return v1 < v2;
    }
};

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<pair<int,int>>> graph(N+1);
        
    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
    
        graph[u].push_back({v,c});
    }
    
    vector<int> cost(N+1,(int)1e16);
    cost[1] = 0;

    multiset<int,Comp> heap((Comp(cost)));
    heap.insert(1);

    vector<int> routes(N+1,0);
    routes[1] = 1;

    vector<int> lflights(N+1,1e8);
    vector<int> rflights(N+1,0);

    lflights[1] = 0;
    rflights[1] = 0;

    while(heap.size())
    {
        int u = *heap.begin();
        heap.erase(heap.begin());

        for(auto [v,vc] : graph[u])
        {
            int nc = cost[u] + vc;
            if(nc < cost[v])
            {
                if(cost[v] < 1e16)
                {
                    heap.erase(v);
                }

                cost[v] = nc;
                routes[v] = routes[u];

                lflights[v] = lflights[u] + 1;
                rflights[v] = rflights[u] + 1;

                heap.insert(v);
            }
            else if(nc == cost[v])
            {
                routes[v] = (routes[v] + routes[u])%MOD;

                lflights[v] = min(lflights[v],lflights[u]+1);
                rflights[v] = max(rflights[v],rflights[u]+1);
            }
        }
    }

    cout << cost[N] << ' ' << routes[N] << ' ' << lflights[N] << ' ' << rflights[N] << '\n';
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