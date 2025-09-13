#include <bits/stdc++.h>
using namespace std;

#define ump unordered_map

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

int get_a(int a,int* P){return P[a];}

void union_s(int a,int b,int* P,ump <int,vector<int>,custom_hash> & mp)
{
    if(P[a]==P[b])return;

    if(mp[P[a]].size() > mp[P[b]].size())swap(a,b);

    vector<int> & v1 = mp[P[b]];
    vector<int> & v2 = mp[P[a]];

    for(int x : v2)P[x] = P[b];

    v1.insert(v1.end(),v2.begin(),v2.end());
    v2.clear();
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> hands(N+1,vector<int>(3));
    for(int i=1;i<=N;i++)
    {
        cin>> hands[i][1] >> hands[i][2];
    }

    int inp[M][2];
    vector<vector<int>> currhands = hands;
    for(int i=0;i<M;i++)
    {
        cin>>inp[i][0]>>inp[i][1];
        currhands[inp[i][0]][inp[i][1]] = -1;
    }

    ump <int,vector<int>,custom_hash> mp;
    int P[N+1];
    for(int i=1;i<=N;i++)mp[i].push_back(i),P[i] = i;
    
    for(int i=1;i<=N;i++)
    {
        auto & v = currhands[i];
        if(v[1]!=-1)union_s(i,v[1],P,mp);
        if(v[2]!=-1)union_s(i,v[2],P,mp);
    }

    vector<int> ans(N+1,-1);
    for(int i=1;i<=N;i++)
    {
        int root = get_a(1,P);
        int p = get_a(i,P);

        if(root!=p)ans[i] = M;
    }

    for(int i=M-1;i>=0;i--)
    {
        int root = get_a(1,P);
        int monk = inp[i][0],hand = inp[i][1];
        if(hands[monk][hand]==-1)continue;

        int p1 = get_a(monk,P),p2 = get_a(hands[monk][hand],P);
        
        int pp = -1;
        if(p1 == root && p2!=root)pp = p2;
        else if(p2 == root && p1!=root)pp = p1;

        if(pp!=-1)
        {
            for(int x : mp[pp])ans[x] = i;
        }

        union_s(monk,hands[monk][hand],P,mp);
    }

    for(int i=1;i<=N;i++)
    {
        cout << ans[i] << '\n';
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}