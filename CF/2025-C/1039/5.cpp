#include <bits/stdc++.h>
using namespace std;

int lin,rin;

bool good(vector<int> & ar,int K,int subm)
{
    int N = ar.size();
    vector<int> precomp(N,0);
    precomp[0] = (ar[0] >= subm)?1:-1;
    for(int i=1;i<N;i++)
    {
        precomp[i] = precomp[i-1] + ((ar[i] >= subm)?1:-1);
    }

    int least = 0,li = 1;
    for(int i=K-1;i<N;i++)
    {
        if(precomp[i] >= least)
        {
            lin = li;
            rin = i+1;
            return true;
        }

        if(precomp[i-K+1] < least)
        {
            least = precomp[i-K+1];
            li = i-K+3;
        }
    }

    return false;
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

    int l = 0,r = N+1;
    while(l+1<r)
    {
        int mid = (l+r)>>1;
        if(good(ar,K,mid))l = mid;
        else r = mid;

        // cout << l << ' ' << r << '\n';
    }

    cout << l << ' ' << lin << ' ' << rin << '\n';
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