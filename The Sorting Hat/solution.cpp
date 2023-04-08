#include <iostream>
int v[200400];
int tree[810000];
void init(int node, int a, int b)
{
    if (a == b)
    {
        tree[node] = v[a];
        return;
    }
    init(2*node+1, a, (a + b)/2);
    init(2*node+2, (a+b)/2+1, b);
    tree[node] = std::min(tree[2*node+1], tree[2*node+2]);
}
int query(int node, int a, int b, int p, int q)
{
    if (q < a || b < p) return 1e9+10;
    if (p <= a && b <= q) return tree[node];
    return std::min(query(2*node+1, a, (a+b)/2, p, q), query(2*node+2, (a+b)/2+1, b, p, q));
}

void update(int node, int a, int b, int p, int val)
{
    if (p < a || b < p) return;
    if (a == b)
    {
        tree[node] = val;
        return;
    }
    update(2*node+1, a, (a+b)/2, p, val);
    update(2*node+2, (a+b)/2+1, b, p, val);
    tree[node] = std::min(tree[2*node+1], tree[2*node+2] );
}
int main()
{
    int n;
    for(int i=0; i<200002; i++)v[i]=1e9+10;
    init(0, 0, 200001);
    int l=0, r=0;
    std::cin>>n;
    while(n--)
    {
        std::string s;
        std::cin>>s;
        if(s=="enqueue")
        {
            std::cout<<"ok";
            int x;
            std::cin>>x;
            v[r]=x;
            update(0, 0, 200001, r, x);
            r++;
        }
        if(s=="front")
        {
            if(l==r)std::cout<<"error";
            else std::cout<<v[l];
        }
        if(s=="dequeue")
        {
            if(l==r)std::cout<<"error";
            else
            {
                std::cout<<v[l];
                v[l]=-1;
                l++;
            }
        }
        if(s=="size")
        {
            std::cout<<r-l;
        }
        if(s=="clear")
        {
            std::cout<<"ok";
            l=r;
        }
        if(s=="min")
        {
            if(l==r)std::cout<<"error";
            else{
                int answer=query(0, 0, 200001, l, r-1);
                 std::cout<<answer;
            }
        }
        std::cout<<"\n";
    }
}
