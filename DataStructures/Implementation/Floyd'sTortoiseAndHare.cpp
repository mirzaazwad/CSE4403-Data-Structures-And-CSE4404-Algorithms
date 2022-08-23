//purpose: finding the half of the linked list and returning it
#include<bits/stdc++.h>
using namespace std;

namespace Singly{
    template<typename T>class Node{
            public:
            T value;
            Node<T>* next;
            Node<T>* previous;
        };

template<typename T>class LinkedList{
    public:
    Node<T> *head, *tail;
    int numberOfItems;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        numberOfItems =0;
    }

    void PushFront(T n)
    {
            numberOfItems++;
            Node<T> *newNode=new Node<T>();
            newNode->value=n;
            newNode->next=head;
            if(head==nullptr){
                tail=newNode;
            }
            head=newNode;
    }

    void pop_front(){
            numberOfItems--;
            Node<T> *temp=head;
            head=head->next;
            delete(temp);
        }

    void push_back(T n){
            numberOfItems++;
            Node<T>* newNode=new Node<T>();
            newNode->value=n;
            newNode->next=nullptr;
            if(head==nullptr){
                head=newNode;
                tail=newNode;
            }
            else if(head->next==nullptr){
                head->next=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
    }

    void display()
    {
        Node<T>* cur=cur=head;
            while(cur!=nullptr){
                cout<<cur->value<<" ";
                cur=cur->next;
        }
        cout<<endl;
    }

    LinkedList<T> getHalf(){

        Node<T>* slow=new Node<T>();
        slow=head;
        Node<T>* fast=new Node<T>();
        fast=head;
        LinkedList<T> list;
        bool fastFound=false;
        while(slow!=nullptr){
            if(fastFound){
                list.push_back(slow->value);
            }
            else{
                if(fast->next!=nullptr){
                    fast=fast->next->next;
                    if(fast==nullptr){
                        fastFound=true;
                        list.push_back(slow->value);
                    }
                }
                else{
                    fast=nullptr;
                    fastFound=true;
                    list.push_back(slow->value);
                }
            }
            slow=slow->next;
        }
        delete(slow);
        delete(fast);
        return list;
    }
};
}



int main()
{
    Singly::LinkedList<int> a;
    int n;
    int i=0;
    while(cin>>n){
        a.push_back(n);
    }
    a=a.getHalf();
    a.display();

    
    



}
