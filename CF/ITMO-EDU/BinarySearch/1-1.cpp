#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'

int binarysearch(vector<int> &array,int tofind,int first,int last)
{
    if(array[first]==tofind||array[last]==tofind)return 1;
    else if(first==last-1)return 0;

    int middle=(first)+(last-first)/2;
    if(tofind==array[middle])return 1;
    else if(tofind>array[middle])return binarysearch(array,tofind,middle,last);
    else return binarysearch(array,tofind,first,middle);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K;
    cin>>N>>K;

    vector<int> input,output;
    int temp;
    while(N--)
    {
        cin>>temp;
        input.push_back(temp);
    }

    while(K--)
    {
        cin>>temp;
        if(temp<input[0]||temp>input[input.size()-1])temp=0;
        else temp=binarysearch(input,temp,0,input.size()-1);
        
        if(temp==0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}