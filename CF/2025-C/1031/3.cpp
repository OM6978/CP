#include <bits/stdc++.h>
using namespace std;

int query(vector<vector<int>> & prexy,int x1,int x2,int y1,int y2)
{
    int N = prexy.size(),M = prexy[0].size();
    int ans = 0; 

    if(x1 > x2)swap(x1,x2);
    x1 = max(0,x1);
    x2 = min(N-1,x2);

    if(y1 > y2)swap(y1,y2);
    y1 = max(0,y1);
    y2 = min(M-1,y2);
    
    if(x1!=0)ans-= prexy[x1-1][y2];
    if(x1!=0 && y1!=0)ans+= prexy[x1-1][y1-1];
    if(y1!=0)ans -= prexy[x2][y1-1];
    
    ans+= prexy[x2][y2];

    return ans;
}

vector<vector<int>> prenit(vector<vector<int>> & mat)
{
    int N = mat.size(),M = mat[0].size();
    vector<vector<int>> prexy(N,vector<int>(M,0));

    prexy[0][0] = (mat[0][0] == 'g');
    for(int j=1;j<M;j++)prexy[0][j] += (mat[0][j] == 'g') + prexy[0][j-1];

    for(int i=1;i<N;i++)
    {
        prexy[i][0] = prexy[i-1][0] + (mat[i][0] == 'g');
        for(int j=1;j<M;j++)
        {
            prexy[i][j] = prexy[i-1][j] + prexy[i][j-1] - prexy[i-1][j-1] + (mat[i][j] == 'g');
        }
    }

    return prexy;
}

void solve()
{
    int N,M,K;
    cin>>N>>M>>K;

    vector<vector<int>> mat(N,vector<int>(M));
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;

        for(int j=0;j<M;j++)
        {
            mat[i][j] = s[j];
        }
    }

    auto prexy = prenit(mat);

    int least = 1e8;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int q = 1e8;
            if(mat[i][j] == '.')
                q = query(prexy,i-K+1,i+K-1,j-K+1,j+K-1);

            least = min(q,least);
        }
    }

    cout << query(prexy,0,N-1,0,M-1) - least << '\n';
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