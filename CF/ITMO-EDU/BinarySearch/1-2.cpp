#include <bits/stdc++.h>
// using namespace std;

#define space " "
#define endl '\n'
#define int long long


std::vector<int> array;

int iterate(int index,int tofind)
{
    int i;
    for(i=index;array[i]==tofind&&(i<array.size());i++);

    return i-1;
}

int binarysearch(int tofind,int first,int last)
{
    if(first==last&&array[first]<=tofind)return first;
    else if(first==last&&array[first]>tofind)return first-1;

    int middle = (first+last)/2;
    if(tofind<array[middle])return binarysearch(tofind,first,middle-1);
    else if(tofind>array[middle])return binarysearch(tofind,middle+1,last);
    else return iterate(middle,tofind);
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int N,K;
    std::cin>>N>>K;

    int temp;
    while(N--)
    {
        std::cin>>temp;
        array.push_back(temp);
    }

    while(K--)
    {
        std::cin>>temp;
        if(temp<array[0])temp=-1;
        else if(temp>=array[array.size()-1])temp=array.size()-1;
        else temp=binarysearch(temp,0,array.size()-1);
        
        std::cout<<temp+1<<endl;
    }
    return 0;
}