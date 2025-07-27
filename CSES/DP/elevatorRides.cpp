#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,X;
    cin>>N>>X;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<int> conts;
    sort(ar.begin(),ar.end(),greater<int>());

    for(int i=0;i<N;i++)
    {
        int flag = 0;
        for(int & cont : conts)
        {
            if(cont + ar[i] <= X)
            {
                flag = 1;
                cont += ar[i];
                break;
            }
        }

        if(flag==0)
        {
            conts.push_back(ar[i]);
        }
    }

    cout << conts.size() << '\n';
    for(int cont : conts)
    {
        cout << cont << ' ';
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
    
    solve();

    return 0;
}