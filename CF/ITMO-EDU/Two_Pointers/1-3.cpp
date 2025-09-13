#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '
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
    int N,M;
    cin>>N>>M;

    unordered_map<int,int,custom_hash> m1,m2;

    int a[N],b[M];
    for(int i=0;i<N;i++)
    {   
        cin>>a[i];
        m1[a[i]]++;
    }
    for(int i=0;i<M;i++)
    {
        cin>>b[i];
        m2[b[i]]++;
    }

    int ans = 0;
    for(auto [x,y] : m1)
    {
        if(m2[x]!=0)
            ans+= y*m2[x];
    }

    cout<<ans<<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}