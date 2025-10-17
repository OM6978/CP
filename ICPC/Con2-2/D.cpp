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

void mexAns(vector<pair<int,int>> & period,int & delight,string & schedule)
{
    for(auto [s,e] : period)
    {
        if(s >= e)
        {
            delight += s;
            schedule.push_back('S');
        }
        else
        {
            delight += e;
            schedule.push_back('E');
        }
    }
}

void sovlePeriod(vector<pair<int,int>> & period,int & delight,string & schedule,int Ms,int Me,int K)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> sHeap,eHeap;
    for(int i=0;i<K;i++)
    {
        auto [s,e] = period[i];
        sHeap.push({s,i});
        eHeap.push({e,i});
    }

    vector<bool> picks(K);
    while(Ms)
    {
        auto [s,is] = sHeap.top();
        auto [e,ie] = eHeap.top();

        sHeap.pop();

        
    }

    while(Me)
    {

    }
}

void solve()
{
    int N,K,Ms,Me;
    cin>>N>>K>>Ms>>Me;

    vector<vector<pair<int,int>>> periods;
    int i=0;
    while(i<N)
    {
        int j = 0;
        periods.push_back({});

        while(j < K && i < N)
        {
            int s,e;
            cin>>s>>e;

            periods.back().push_back({s,e});

            i++;
            j++;
        }
    }

    int delight = 0;
    string schedule;

    for(auto period : periods)
    {
        int psz = period.size();
        if(psz < K)
        {
            mexAns(period,delight,schedule);
        }
        else
        {
            sovlePeriod(period,delight,schedule,Ms,Me,K);
        }
    }

    cout << delight << '\n';
    cout << schedule << '\n';
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