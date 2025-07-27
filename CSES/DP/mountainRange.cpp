#include <bits/stdc++.h>
using namespace std;

#define int long long

template <typename T>
class SegmentTree {
private:
    int n;
    std::vector<T> st;
    T null_val;
    std::function<T(T, T)> operation;

    void build(const std::vector<T>& ar, int x, int lx, int rx) {
        if (rx - lx == 1)
        {
            if (lx < ar.size())
            {
                st[x] = ar[lx];
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(ar, 2 * x + 1, lx, mid);
        build(ar, 2 * x + 2, mid, rx);
        st[x] = operation(st[2 * x + 1], st[2 * x + 2]);
    }

    void set(int i, T v, int x, int lx, int rx) {
        if (rx - lx == 1)
        {
            st[x] = v;
            return;
        }
        
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        st[x] = operation(st[2 * x + 1], st[2 * x + 2]);
    }

    // Private recursive helper for range queries
    T query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) { // No overlap
            return null_val;
        }
        if (lx >= l && rx <= r) { // Total overlap
            return st[x];
        }
        int mid = (lx + rx) / 2;
        T res1 = query(l, r, 2 * x + 1, lx, mid);
        T res2 = query(l, r, 2 * x + 2, mid, rx);
        return operation(res1, res2);
    }

public:
    // Constructor
    SegmentTree(const std::vector<T>& ar, T null_value, std::function<T(T, T)> op)
        : null_val(null_value), operation(op) {
        n = 1;
        while (n < ar.size()) {
            n <<= 1; // Find the smallest power of 2 >= array size
        }
        st.assign(2 * n - 1, null_val);
        build(ar, 0, 0, n);
    }

    // Public wrapper for range query on [l, r)
    T query(int l, int r) {
        return query(l, r, 0, 0, n);
    }

    // Public wrapper for point update at index i
    void set(int i, T v) {
        set(i, v, 0, 0, n);
    }
};

int getmts(int prev,int l,int r,SegmentTree<pair<int,int>> & st)
{
    if(l>=r)return 0;
    
    auto [most,in] = st.query(l,r);

    int m1 = getmts(most,l,in,st);
    int m2 = getmts(most,in+1,r,st);

    return max(m1,m2) + (most!=prev);
}

void solve()
{
    int N;
    cin>>N;

    vector<pair<int,int>> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i].first;
        ar[i].second = i;
    }

    auto max_op = [](pair<int,int> a, pair<int,int> b)
    {
        if(a.first > b.first)
        {
            return make_pair(a.first,a.second);
        }
        return make_pair(b.first,b.second);
    };

    SegmentTree<pair<int,int>> st(ar,make_pair(0,-1),max_op);

    cout << getmts(-1,0,N,st) << '\n';
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