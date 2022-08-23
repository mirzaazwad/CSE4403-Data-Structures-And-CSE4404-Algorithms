

#include<bits/stdc++.h>
using namespace std;


struct node
{
    int val;
    node * next;
};

class Singly_linked_list{
public:
    node *head, *tail;

    Singly_linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void PushFront(int n)
    {

    }

    void display()
    {
        node *cur = head;

        while(cur != nullptr)
        {
            cout << cur->val << endl;
            cur = cur->next;
        }
        cout<<endl;
    }

    void Reverse()
    {

        

    }



};



int main()
{
    Singly_linked_list a;
    for(int i =1 ; i < 10; i++)
        a.PushFront(i);

    a.display();
    a.Reverse();
    a.PushFront(100);
    a.display();



}
