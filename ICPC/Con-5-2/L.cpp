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

    if(N == 1)
    {
        cout << "Yes\n";
        cout << 0 << '\n' << 0 << '\n';
        return;
    }
    else if(N%4 != 0)
    {
        cout << "No\n";
        return;
    }

    unordered_map<int,int,custom_hash> numState;
    for(int i=0;i<N;i++)
    {
        numState[i] = 3;
    }

    int odd = 0;
    int even = 0;

    bool flag = true;

    int oddl = 1;
    int oddr = ((N-1)&1)?N-1:N-2;

    int evenl = 0;
    int evenr = ((N-1)&1)?N-2:N-1;

    int oup = 0;
    int odown = 0;

    int eup = 0;
    int edown = 0;

    for(int i=N-1;i>=0;i--)
    {
        if(i&1)
        {
            if(flag)
            {
                if(up >= down)
                {
                    int 
                }
                else
                {

                }
            }
            else
            {

            }

            flag = !flag;
        }
        else
        {

        }
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