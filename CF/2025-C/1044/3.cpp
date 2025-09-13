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

void ask(int beg,vector<int> askv)
{
    cout << "? " << beg << ' ' << askv.size() << ' ';
    for(int a : askv)
    {
        cout << a << ' ';
    }
    cout << '\n';
}

void solve()
{
    int N;
    cin>>N;

    vector<int> fask(N);
    iota(fask.begin(),fask.end(),1);

    unordered_map<int,vector<int>,custom_hash> pathHash; 

    int most = 0;
    for(int i=1;i<=N;i++)
    {
        ask(i,fask);

        int locs;
        cin>>locs;

        most = max(most,locs);
        pathHash[locs].push_back(i);
    }

    int x = pathHash[most][0];
    int xpath = most-1;

    vector<int> ans = {x};

    // cout << xpath << ' ' << x << '\n';

    while(xpath!=0)
    {
        for(int y : pathHash[xpath])
        {
            ask(x,{x,y});

            int locs;
            cin>>locs;

            if(locs == 2)
            {
                x = y;
                xpath--;
                ans.push_back(y);

                break;
            }
        }
    }

    cout << "! " << ans.size() << ' ';
    for(int a : ans)
    {
        cout << a << ' ';
    }
    cout << '\n';
}

signed main()
{    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}