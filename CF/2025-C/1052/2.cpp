#include <bits/stdc++.h>
using namespace std;

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

bool allEqSets(vector<vector<int>> & vSets,vector<int> & xtraSets)
{
    auto ref = xtraSets[0];
    for(int i=1;i<(int)xtraSets.size();i++)
    {
        if(xtraSets[i] != ref)
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> vSets(N);

    unordered_map<int,vector<int>,custom_hash> invFile;
    unordered_map<int,int,custom_hash> efreq;

    for(int i=0;i<N;i++)
    {
        int ssz;
        cin>>ssz;

        vSets[i].resize(ssz);
        for(int j=0;j<ssz;j++)
        {
            cin>>vSets[i][j];
            invFile[vSets[i][j]].push_back(i);
            efreq[vSets[i][j]]++;
        }
    }

    for(int e=1;e<=M;e++)
    {
        if(efreq[e] == 0)
        {
            cout << "NO\n";
            return;
        }
    }

    vector<int> vis(M+1,0);
    vector<int> svis(N,0);

    for(auto [val,f] : efreq)
    {
        if(f == 1)
        {
            vis[val] = 1;
            svis[invFile[val][0]] = 1;
        }
    }

    vector<int> xtraSets;
    for(int i=0;i<N;i++)
    {
        if(svis[i] == 0)
        {
            xtraSets.push_back(i);
        }
    }
    
    if(xtraSets.size() >= 2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}