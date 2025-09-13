#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,M,K;
    cin>>N>>M>>K;

    vector<vector<pair<int,int>>> graph(N+1);
        
    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
    
        graph[u].push_back({v,c});
    }

    multiset<pair<int,int>> ms;
    ms.insert({0,1});

    vector<int> cnt(N+1);
    vector<int> ans;

    while(ms.size())
    {
        auto [price,u] = *ms.begin();
        ms.erase(ms.begin());

        cnt[u]++;

        if(cnt[u] <= K)
        {
            for(auto [v,c] : graph[u])
            {
                if(cnt[v] <= K)
                    ms.insert({price + c,v});
            }
        }

        if(u == N)
        {
            ans.push_back(price);
            if(ans.size() == K)break;
        }
    }

    for(int a : ans)
    {
        cout << a << ' ';
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