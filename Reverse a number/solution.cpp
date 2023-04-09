#include <iostream>

int main()
{
    unsigned long long int n;
    while(std::cin>>n)
    {
        unsigned long long int m=0;
        while(n!=0)
        {
            m*=10;
            m+=(n%10);
            n/=10;
        }
        std::cout<<m<<std::endl;
    }
}
