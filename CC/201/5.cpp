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

void solve()
{
    int N;
    cin>>N;
    
    set<int> indOrder;
    unordered_map<int,int,custom_hash> indHash;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        indOrder.insert(i);
        indHash[ar[i]] = i;
    }

    auto sar = ar;
    sort(sar.begin(),sar.end(),greater<int>());

    int ans = 0;
    for(int i=0;i<N;i++)
    {
        int in = indHash[sar[i]];
        int front = *indOrder.begin();
        int back = *indOrder.rbegin();

        if(in == front || in == back)
        {
            ans = (ans + indOrder.size())%MOD;
        }
        else
        {
            ans++;
        }

        // cout << in << ' ' << front << ' ' << back << ' ';
        // cout << ans << '\n';

        indOrder.erase(in);
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
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}