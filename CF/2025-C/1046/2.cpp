#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,K;
    cin>>N>>K;

    string s;
    cin>>s;

    vector<int> P(N);

    int st = 1;
    for(int i=0;i<N;i++)
    {
        if(s[i] == '1')
        {
            P[i] = st++;
        }
    }

    for(int i=0;i<N;i++)
    {
        if(s[i] == '0')
        {
            P[i] = st++;
        }
    }

    int curr =0;
    for(int i=0;i<N;i++)
    {
        if(s[i] == '1')
        {
            curr++;
            if(curr >= K)
            {
                cout << "NO\n";
                return;
            }
        }
        else curr = 0;
    }

    cout << "YES\n";

    for(int i=0;i<N;i++)
    {
        cout << P[i] << ' ';
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