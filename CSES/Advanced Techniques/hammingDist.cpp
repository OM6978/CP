#include <bits/stdc++.h>
using namespace std;

struct Node
{
    bool leaf;
    int children[2];

    Node()
    {
        leaf = false;
        children[0] = 0;
        children[1] = 0;
    }
};

int dInsert(string code,vector<Node> & trie)
{
    int cNode = 0;

    int similarity = 0;
    for(int a : code)
    {
        int dig = a - '0';
        if(trie[cNode].children[dig])
        {
            similarity++;
        }
        else
        {
            trie[cNode].children[dig] = trie.size();
            trie.push_back({});
        }

        cNode = trie[cNode].children[dig];
    }

    return similarity;
}

void solve()
{
    int N,K;
    cin>>N>>K;

    vector<Node> trie(1);
    
    int ans = K+1;
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;

        ans = min(ans,dInsert(s,trie));
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