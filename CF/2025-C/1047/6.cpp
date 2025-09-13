#include <bits/stdc++.h>
using namespace std;

#define int long long

void push(int in,vector<int> & stk,vector<int> & vstk,vector<int> & ar)
{
    while(stk.size())
    {
        if(vstk.back() >= ar[in])
        {
            break;
        }
        else
        {
            stk.pop_back();
            vstk.pop_back();
        }
    }

    stk.push_back(in);
    vstk.push_back(ar[in]);
}

int contriInd(int in,vector<int> & stk,vector<int> & vstk,vector<int> & y)
{
    int ind = upper_bound(vstk.begin(),vstk.end(),y[in],greater<int>()) - vstk.begin();
    // cout << "IND : " << ind << '\n';
    if(ind == vstk.size())
    {
        return in+1;
    }
    else return stk[ind]+1;
}

void solve()
{
    int N;
    cin>>N;

    vector<int> x(N);
    vector<int> y(N);

    for(int i=0;i<N;i++)
    {
        cin>>x[i];
    }

    for(int i=0;i<N;i++)
    {
        cin >> y[i];
    }

    vector<int> indStk;
    vector<int> valStk;

    int ans = 0;
    for(int i=0;i<N;i++)
    {
        push(i,indStk,valStk,x);
        int ind = contriInd(i,indStk,valStk,y);

        ans += (ind-1 + (x[i] == y[i]))*(N-ind+1);
        
        // cout << "Stack: \n";
        // for(int j=0;j<valStk.size();j++)
        // {
        //     cout << indStk[j] << ' ' << valStk[j] << '\n';
        // }

        cout << ind << ' ';
        cout << ans << '\n';
    }

    cout << ans << '\n';
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