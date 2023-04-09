#include <iostream>

struct node
{
    char data;
    struct node* next;
    node(char  data)
    {
        this->data = data;
        next = NULL;
    }
};
struct lilist
{
    node* head;
    lilist()
    {
        head = NULL;
    }
    void print()
    {
        struct node* puntero = head;
        while (puntero != NULL)
        {
            std::cout << puntero->data;
            puntero = puntero->next;
        }
    }
    void push(char data)
    {
        node* puntero = new node(data);
        puntero->next = head;
        head = puntero;
    }
};
int main()
    
{
    std::string s;
    while(getline(std::cin, s))
    {
        lilist lista;
        int n=s.size();
        for(int i=0; i<n; i++)
        {
            lista.push(s[i]);
        }
        lista.print();
        std::cout<<"\n";
    }
}
