#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int an;
    cin>>an;
    
    string a;
    cin>>a;

    int N;
    cin>>N;

    string b,c;
    cin>>b>>c;

    string vs,ds;
    for(int i=0;i<N;i++)
    {
        if(c[i] == 'V')
        {
            vs.push_back(b[i]);
        }
        else
        {
            ds.push_back(b[i]);
        }
    }

    reverse(vs.begin(),vs.end());

    string out = vs;
    out.insert(out.end(),a.begin(),a.end());
    out.insert(out.end(),ds.begin(),ds.end());

    cout << out << '\n';
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