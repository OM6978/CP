#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    string s;
    cin>>s;

    s.insert(s.begin(),{'0','0'});
    s.insert(s.end(),{'0','0'});

    for(int i=2;i<N+2;i++)
    {
        int num = s[i] - '0';
        if(num == 1)
        {
            bool pos = false;
            if(s[i+1] == '1' && s[i+2] == '1')pos = true;
            else if(s[i-1] == '1' && s[i-2] == '1')pos = true;
            else if(s[i-1] == '1' && s[i+1] == '1')pos = true;

            if(!pos)
            {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
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