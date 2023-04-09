#include <iostream>
int v[100030];
bool bs(int l, int r, int t)
{
    r--;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(v[mid]<t)l=mid+1;
        else r=mid;
    }
    return t==v[l];
}
int main()
{
    int n;
    while(std::cin>>n)
    {
        for(int i=0; i<n; i++)std::cin>>v[i];
        int q;
        std::cin>>q;
        while(q--)
        {
            int l, r, t;
            std::cin>>l>>r>>t;
            if(bs( l,  r ,  t))std::cout<<"YES"<<"\n";
            else std::cout<<"NO"<<"\n";
        }
    }
}
