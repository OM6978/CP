#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<vector<int>> mat(N,vector<int>(N));
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;

        for(int j=0;j<N;j++)
        {
            mat[i][j] = s[j];
        }
    }

    auto isvalid = [&](int x,int y) -> bool
    {
        return (x>=0 && x<N && y>=0 && y<N);
    };

    queue<pair<int,int>> q;
    vector<pair<int,int>> next;
    vector<vector<int>> vis(N,vector<int> (N,0));

    string ans;
    ans.push_back(mat[0][0]);
    q.push({0,0});
    while(q.size())
    {
        int cnt = q.size();
        while(cnt--)
        {
            auto p = q.front();
            q.pop();

            if(isvalid(p.first,p.second+1))next.push_back({p.first,p.second+1});
            if(isvalid(p.first+1,p.second))next.push_back({p.first+1,p.second});
        }

        int least=1e4;
        for(auto p : next)
        {
            int val = mat[p.first][p.second];
            least = min(least,val);
        }
        if(least < 100)ans.push_back(least);

        for(auto p : next)
        {
            if(mat[p.first][p.second]!=ans.back())continue;

            if(vis[p.first][p.second]==0)
            {
                q.push(p);
            }
            vis[p.first][p.second] = 1;
        }

        next.clear();
    }

    cout << ans << '\n';
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