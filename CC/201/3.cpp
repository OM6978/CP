#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    string s;
    cin>>s;

    int sum = 0;
    for(int a : s)
    {
        sum += a - '0';
    }

    cout << 3*sum - s[N-1] + '0' - s[0] + '0' << '\n';
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