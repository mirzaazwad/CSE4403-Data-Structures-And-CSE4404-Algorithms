#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *parent;
    Node *right;
    Node *left;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node *root = nullptr;
    int Max=INT_MIN;

public:
    void Insert(int key)
    {
        Node *insertNode = new Node(key);
        Node *t = root;
        Node *temp = nullptr;
        while (t != nullptr)
        {
            temp = t;
            if (insertNode->data < t->data)
            {
                t = t->left;
            }
            else
            {
                t = t->right;
            }
        }
        insertNode->parent = temp;
        if (temp == nullptr)
        {
            root = insertNode;
        }
        else if (insertNode->data < temp->data)
        {
            temp->left = insertNode;
        }
        else
            temp->right = insertNode;
    }

    Node *Search(int key, Node *t = nullptr, bool set = false)
    {
        if (!set)
        {
            set = true;
            t = root;
        }
        if (t == nullptr)
            return nullptr;
        if (key == t->data)
            return t;
        else if (key < t->data)
            return Search(key, t->left, true);
        else
            return Search(key, t->right, true);
    }

    void Inorder(Node *t = nullptr, bool set = false)
    {
        if (t == nullptr)
        {
            if (!set)
            {
                t = root;
                set = true;
                Inorder(t, set);
            }
            return;
        }
        Inorder(t->left, set);
        cout << t->data << " ";
        Inorder(t->right, set);
    }

    Node *Predecessor(Node *p)
    {
        while (p && p->right != nullptr)
        {
            p = p->right;
        }
        return p;
    }

    int InorderPredecessor()
    {
        return Predecessor(root->left)->data;
    }

    Node *Successor(Node *p)
    {
        while (p && p->left != nullptr)
        {
            p = p->left;
        }
        return p;
    }

    int InorderSuccessor()
    {
        return Successor(root->right)->data;
    }

    void LevelOrderintraversal()
    {
        queue<Node *> q, level;
        q.push(root);
        while (!q.empty())
        {
            while (!q.empty())
            {
                cout << q.front()->data << " ";
                if (q.front()->left != nullptr)
                    level.push(q.front()->left);
                if (q.front()->right != nullptr)
                    level.push(q.front()->right);
                q.pop();
            }
            cout << endl;
            while (!level.empty())
            {
                q.push(level.front());
                level.pop();
            }
        }
    }

    int findMax(int start,int end){
        Node* bg=Search(start);
        Node* fin=Search(end);
        Node* curr=bg;
        bool found=false;
        int Max=curr->data;
        while(true){
            Max=max(Max,curr->data);
            if(fin->data>curr->data){
                curr=curr->right;
            }
            else if(fin->data==curr->data){
                found=true;
                break;
            }
            else{
                curr=curr->left;
            }
            if(!found && curr==nullptr){
                Max=max(bg->data,bg->parent->data);
                bg=bg->parent;
                curr=bg;
            }

        }
        return Max;
    }



    
};

int main(void)
{
    BinarySearchTree tree = BinarySearchTree();
    int n;
    while (cin >> n, n != -1)
    {
        tree.Insert(n);
    }
    int q;
    cin>>q;
    while(q--){
        int start,end;
        cin>>start>>end;
        if(tree.Search(start)==nullptr){
            tree.Insert(start);
        }
        if(tree.Search(end)==nullptr){
            tree.Insert(end);
        }
        cout<<tree.findMax(start,end)<<endl;
    }
}