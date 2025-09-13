#include <bits/stdc++.h>
using namespace std;

#define int long long

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
    int N,K;
    cin>>N>>K;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    int l = 0,r = -1,ans = 0;
    unordered_map<int,int,custom_hash> m1;

    int unique = 0;
    while(r!=N)
    {
        if(unique > K)
        {
            m1[ar[l]]--;

            if(m1[ar[l]] == 0)unique--;
            l++;
        }
        else
        {
            ans+= (r++-l+1);

            if(r!=N)
            {
                m1[ar[r]]++;
                if(m1[ar[r]]==1)unique++;
            }
        }
    }

    cout<<ans<<'\n';
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