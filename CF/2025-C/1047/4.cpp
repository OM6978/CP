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

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    unordered_map<int,int,custom_hash> freqz;
    for(int i=0;i<N;i++)
    {
        freqz[ar[i]]++;
    }

    unordered_map<int,vector<int>,custom_hash> freqelems;
    unordered_map<int,int,custom_hash> donefreqz;

    int e = 1;
    for(auto [x,f] : freqz)
    {
        if(f%x != 0)
        {
            cout << -1 << '\n';
            return;
        }

        int d = f/x;
        for(int i=0;i<d;i++)
        {
            freqelems[x].push_back(e++);
        }
    }

    for(int i=0;i<N;i++)
    {
        int & donef = donefreqz[ar[i]];
        if(donef == ar[i])
        {
            donef = 0;
            freqelems[ar[i]].pop_back();
        }

        cout << freqelems[ar[i]].back() << ' ';
        donef++;
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
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}