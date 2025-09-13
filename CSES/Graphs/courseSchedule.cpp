#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<int>> & graph)
{
    int N = graph.size()-1;
    vector<int> indeg(N+1,0);

    for(int i=1;i<=N;i++)
    {
        for(int v : graph[i])
        {
            indeg[v]++;
        }
    }

    queue<int> q;
    for(int i=1;i<=N;i++)
    {
        if(indeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> res;
    while(q.size())
    {
        int cnt = q.size();
        while(cnt--)
        {
            int u = q.front();
            q.pop();

            res.push_back(u);

            for(int v : graph[u])
            {
                indeg[v]--;
                if(indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }

    return res;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> graph(N+1,vector<int>());
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;

        graph[a].push_back(b);
    }

    auto courses = topoSort(graph);

    if(courses.size() != N)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(int course : courses)
    {
        cout << course << ' ';
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