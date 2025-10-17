#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int missing;
    int children[2];
    
    bool leaf;

    Node()
    {
        children[0] = 0;
        children[1] = 0;
        missing = 0;
        leaf = false;
    }
};

bool addT(string & code,vector<Node> & trie)
{
    int cNode = 0;
    
    for(int a : code)
    {
        int next;
        if(a == '?')
        {
            if(trie[cNode].missing <= 0)
            {
                trie[cNode].missing = trie.size();
                trie.emplace_back();
            }

            next = trie[cNode].missing;
        }
        else
        {
            if(trie[cNode].children[a - '0'] <= 0)
            {
                trie[cNode].children[a - '0'] = trie.size();
                trie.emplace_back();
            }

            next = trie[cNode].children[a - '0'];
        }

        cNode = next;
    }

    trie[cNode].leaf = true;
}

void addN(int c1,int c2,vector<Node> & trie)
{
    cout << c1 << ' ' << c2 << '\n';
}

void printTrie(int cNode,vector<Node> & trie,string & code)
{
    auto & node = trie[cNode];

    if(node.leaf)
    {
        cout << code << '\n';
    }

    if(node.children[0] > 0)
    {
        code.push_back('0');
        printTrie(node.children[0],trie,code);
        code.pop_back();
    }

    if(node.children[1] > 0)
    {
        code.push_back('1');
        printTrie(node.children[1],trie,code);
        code.pop_back();
    }

    if(node.missing > 0)
    {
        code.push_back('?');
        printTrie(node.missing,trie,code);
        code.pop_back();
    }
}

bool isPrefixable(int c1,int c2,vector<Node> & trie)
{
    if(trie[c1].leaf && trie[c2].leaf)return false;

    bool res = true;
    if(trie[c1].missing>0 && trie[c2].missing>0)
    {
        res = res && isPrefixable(trie[c1].missing,trie[c2].missing,trie);
    }
    else if(trie[c1].missing > 0)
    {
        bool subq = false;
        if(trie[c2].children[0] > 0)
        {
            subq = subq || isPrefixable(trie[c1].missing,trie[c2].children[0],trie);
        }

        if(trie[c2].children[1] > 0)
        {
            subq = subq || isPrefixable(trie[c1].missing,trie[c2].children[1],trie);
        }

        res = res && subq;
    }
    else if(trie[c2].missing > 0)
    {
        bool subq = false;
        if(trie[c1].children[0] > 0)
        {
            subq = subq || isPrefixable(trie[c2].missing,trie[c1].children[0],trie);
        }

        if(trie[c1].children[1] > 0)
        {
            subq = subq || isPrefixable(trie[c2].missing,trie[c1].children[1],trie);
        }

        res = res && subq;
    }

    if(trie[c1].children[0]>0 && trie[c2].children[0]>0)
    {
        res = res && isPrefixable(trie[c1].children[0],trie[c2].children[0],trie);
    }

    if(trie[c1].children[1]>0 && trie[c2].children[1]>0)
    {
        res = res && isPrefixable(trie[c1].children[1],trie[c2].children[1],trie);
    }

    return res;
}

bool solveTrie(int cNode,vector<Node> & trie)
{
    bool res = true;

    if(trie[cNode].missing == 0)
    {
        if(trie[cNode].children[0] > 0)
        {
            res = res && solveTrie(trie[cNode].children[0],trie);
        }

        if(trie[cNode].children[1] > 0)
        {
            res = res && solveTrie(trie[cNode].children[1],trie);
        }
    }
    else
    {
        bool s[2];
        if(trie[cNode].children[0] > 0)
        {
            s[0] = isPrefixable(trie[cNode].missing,trie[cNode].children[0],trie);
        }

        if(trie[cNode].children[1] > 0)
        {
            s[1] = isPrefixable(trie[cNode].missing,trie[cNode].children[1],trie);
        }

        if(s[0])
        {
            addN(trie[cNode].missing,trie[cNode].children[0],trie);
        }
        else if(s[1])
        {
            addN(trie[cNode].missing,trie[cNode].children[1],trie);
        }
        else
        {
            res = false;
        }
    }

    return res;
}

void solve()
{
    int N;
    cin>>N;

    vector<Node> trie(1);

    for(int i=0;i<N;i++)
    {
        string code;
        cin>>code;

        addT(code,trie);
    }

    string tmp;
    if(solveTrie(0,trie))
    {
        cout << "YES\n";
        printTrie(0,trie,tmp);
    }
    else
    {
        cout << "NO\n";
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