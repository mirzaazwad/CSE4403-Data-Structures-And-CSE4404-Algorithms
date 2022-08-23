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

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(T n)
    {
        Node<T> *newNode=new Node<T>();
            newNode->value=n;
            newNode->next=head;
            if(head==nullptr){
                tail=newNode;
            }
            head=newNode;
    }

    void pop_front(){
            Node<T> *temp=head;
            head=head->next;
            delete(temp);
        }

    void push_back(T n){
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

    void pop_back(){
            Node<T>* temp=new Node<T>();
            temp=head;
            if(head->next==nullptr){
                head=nullptr;
                delete(temp);
                return;
            }
            if(head==nullptr){
                throw("No element in list");
            }
            while(temp->next->next!=nullptr){
                temp=temp->next;
            }
            Node<T>* deletable=new Node<T>();
            deletable=temp->next;
            temp->next=nullptr;
            delete(deletable);
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

    void reverse()
    {
        // Initialize current, previous and next pointers
        Node<T>* current = head;
        Node<T> *prev = nullptr, *next = nullptr;
 
        while (current != nullptr) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

};
}



int main()
{
    Singly::LinkedList<int> a;
    for(int i =1 ; i < 10; i++)a.push_front(i);

    a.display();
    a.reverse();
    a.display();




}
