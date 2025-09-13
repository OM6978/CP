#include <bits/stdc++.h>
using namespace std;

void readScore(int lg,int rg,int lp,int rp,bool serve)
{
    cout << lg << ' ';
    cout << '(' << lp;
    if(!serve)cout << '*';
    cout <<  ')' << ' ';

    cout << '-' << ' ';

    cout << rg << ' ';
    cout << '(' << rp;
    if(serve)cout << '*';
    cout << ')' << '\n';
}

void Announcement(int lg,int rg,bool winner)
{
    cout << lg;
    if(!winner)cout << " (winner)";

    cout << ' ' << '-' << ' ';

    cout << rg;
    if(winner)cout << " (winner)\n";
}

void solve()
{
    string s;
    cin>>s;

    int g[2] = {0};
    int p[2] = {0};
    bool serve = 0;

    for(int a : s)
    {
        if(a != 'Q')
        {
            if(a == 'R')
            {
                serve = !serve;
            }

            p[serve]++;

            if((p[serve] >= 5 && p[serve] - p[!serve] >= 2) || p[serve] == 10)
            {
                g[serve]++;
                p[0] = 0;
                p[1] = 0;
            }
        }
        else
        {
            if(abs(g[0] - g[1]) == 2 || g[0] + g[1] == 3)
            {
                bool winner = (g[0] > g[1])?0:1;
                Announcement(g[0],g[1],winner);
            }
            else
            {
                readScore(g[0],g[1],p[0],p[1],serve);
            }
        }

        // cout << g[0] << ' ' << g[1] << '\n';
        // cout << p[0] << ' ' << p[1] << '\n';
        // cout << serve << '\n';
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
    
    solve();

    return 0;
}