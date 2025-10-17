#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    string s;
    cin>>s;

    vector<vector<int>> islands;

    int ce = -1;
    for(int i=0;i<N;i++)
    {
        int a = s[i] - '0';
        if(ce != a)
        {
            islands.push_back({a});
            ce = a;
        }
        
        islands.back().push_back(i+1);
    }
    
    vector<int> res;

    int M = islands.size();
    for(int i=0;i<M;i++)
    {
        if((int)islands[i].size() <= 2 && islands[i][0] == 0)
        {
            cout << "NO\n";
            return;
        }

        auto isle = islands[i];
        int isz = isle.size();

        if(islands[i][0] == 0)
        {
            for(int j=isz-1;j>0;j--)
            {
                res.push_back(isle[j]);
            }
        }
        else
        {
            res.insert(res.end(),isle.begin()+1,isle.end());
        }
    }

    cout << "YES\n";
    for(int a : res)
    {
        cout << a << ' ';
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