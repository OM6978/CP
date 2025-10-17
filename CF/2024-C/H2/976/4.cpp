#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:

    vector<int> P;    // Parent array
    vector<int> rank; // Rank for union by rank heuristic
    vector<int> sz;   // Size of the set (only valid for roots)
    int num_disjoint_sets; // Current count of disjoint sets

    DSU(int n) 
    {
        P.resize(n + 1);
        std::iota(P.begin(), P.end(), 0);
        rank.assign(n + 1, 1);
        sz.assign(n + 1, 1);
        num_disjoint_sets = n;
    }

    int getPar(int a)
    {
        if (P[a] == a) {
            return a;
        }
        return P[a] = getPar(P[a]);
    }

    void unionS(int a, int b)
    {
        int l1 = getPar(a);
        int l2 = getPar(b);

        if (l1 == l2) 
        {
            return;
        }

        if (rank[l1] < rank[l2])
        {
            std::swap(l1, l2);
        }

        P[l2] = l1;
        sz[l1] += sz[l2];
        if (rank[l1] == rank[l2]) {
            rank[l1]++;
        }
        num_disjoint_sets--;
    }


    int getSetSize(int a)
    {
        return sz[getPar(a)];
    }

    int getSz(int par)
    {
        return sz[par];
    }

    int getNumDisjointSets()
    {
        return num_disjoint_sets;
    }
};

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<pair<int,int>>> dpairList(11);

    for(int i=0;i<M;i++)
    {
        int a,d,k;
        cin>>a>>d>>k;

        dpairList[d].push_back({a,k});
    }

    DSU dsu = DSU(N);

    vector<int> aendPoints(N+1);

    for(int d = 1;d <= 10;d++)
    {
        DSU ddsu(N);
        for(int a = 1;a <=N ;a++)
        {
            aendPoints[a] = a;
        }

        for(auto [a,k] : dpairList[d])
        {
            int pa = ddsu.getPar(a);

            int kend = a + d*k;
            int aend = aendPoints[pa];

            while(aend < kend)
            {
                int b = aend + d;
                int pb = ddsu.getPar(b);

                dsu.unionS(pa,pb);
                ddsu.unionS(pa,pb);

                aend = aendPoints[pb];

                pa = ddsu.getPar(a);
                aendPoints[pa] = aend;
            }
        }
    }

    cout << dsu.getNumDisjointSets() << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}