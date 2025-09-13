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

void assignMEX(int mex,unordered_map<int,int,custom_hash> & freqz,vector<int> & ar)
{
    int N = ar.size();
    for(int i=0;i<N;i++)
    {
        if(freqz[ar[i]] > 1 || ar[i] > mex)
        {
            ar[i] = mex;
        }
    }
}

void printArr(vector<int> & ar)
{
    for(int a : ar)
    {
        cout << a << ' ';
    }
    cout << '\n';
}

void processArr(vector<int> & ar)
{
    int N = ar.size();

    unordered_map<int,int,custom_hash> freqz;
    for(int i=0;i<N;i++)
    {
        freqz[ar[i]]++;
    }

    vector<int> uar;
    for(auto [a,_] : freqz)
    {
        uar.push_back(a);
    }

    sort(uar.begin(),uar.end());

    // printArr(ar);
    // printArr(uar);

    int mex=0;
    for(int i=0;i<uar.size();i++)
    {
        if(uar[i] != mex)
        {
            break;
        }
        mex++;
    }

    assignMEX(mex,freqz,ar);
}

void solve()
{
    int N,K;
    cin>>N>>K;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    processArr(ar);

    if(K == 1)
    {
        cout << accumulate(ar.begin(),ar.end(),0LL) << '\n';
        return;
    }

    processArr(ar);

    if(K % 2 == 0)
    {
        cout << accumulate(ar.begin(),ar.end(),0LL) << '\n';
    }
    else
    {
        processArr(ar);

        cout << accumulate(ar.begin(),ar.end(),0LL) << '\n';
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