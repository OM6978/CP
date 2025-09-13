#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;

struct Node
{
    int next[26];
    int par;
    bool leaf;
    Node()
    {
        fill(next,next+26,-1);
        leaf = false;
        par = -1;
    }
};

void add_word(string & word,vector<Node> & trie)
{
    int N = word.size();
    int curr = 0;
    for(int i=0;i<N;i++)
    {
        Node & cNode = trie[curr];
        int par = curr;
        if(cNode.next[word[i] - 'a'] == -1)
        {
            cNode.next[word[i] - 'a'] = trie.size();
            trie.emplace_back();
        }
        curr = trie[curr].next[word[i] - 'a'];
        trie[curr].par = par;
    }
    
    trie[curr].leaf = true;
}

void solve()
{
    string s;
    cin>>s;

    int N = s.size();
    
    int K;
    cin>>K;

    vector<Node> invtrie(1,Node());

    invtrie[0].leaf = true;

    vector<string> words(K);
    for(int i=0;i<K;i++)
    {
        cin>>words[i];
        auto rword = words[i];
        reverse(rword.begin(),rword.end());

        add_word(rword,invtrie);
    }

    vector<int> dp(N+1,0);
    dp[0] = 1;

    for(int i=1;i<=N;i++)
    {
        int cres = 0;
        int curr = 0;

        int skips = 0;
        for(int j=i-1;j>=0;j--)
        {
            if(invtrie[curr].next[s[j] - 'a'] == -1)
            {
                skips = j+1;
                break;
            }
            curr = invtrie[curr].next[s[j] - 'a'];
        }

        for(int j=skips;j<i;j++)
        {            
            if(invtrie[curr].leaf)
            {
                cres = (cres + dp[j])%MOD;
            }

            curr = invtrie[curr].par;
        }

        dp[i] = cres;
    }

    cout << dp[N] << '\n';
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