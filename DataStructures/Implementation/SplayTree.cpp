#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *parent;
    Node<T> *right;
    Node<T> *left;
    Node(T value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

template <typename T>
class SplayTree
{
private:
    Node<T> *root;

public:
    SplayTree()
    {
        root = nullptr;
    }

    void Insert(T key)
    {
        Node<T> *insertNode = new Node<T>(key);
        Node<T> *t = root;
        Node<T> *temp = nullptr;
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
        Splay(insertNode);
    }

    void Splay(Node<T> node)
    {
        while (node->parent != nullptr)
        {
            if (node->parent == root)
            {
                if (node == node->parent->left)
                {
                    RightRotation(node->parent);
                }
                else
                {
                    LeftRotation(node->parent);
                }
            }
            else
            {
                Node<T> *parent = node->parent;
                Node<T> *grandparent = parent->parent;
                if (node == node->parent && parent == parent->left)
                {
                    RightRotation(grandparent);
                    RightRotation(parent);
                }
                else if (node == node->parent->right && parent == parent->parent->right)
                {
                    LeftRotation(grandparent);
                    LeftRotation(parent);
                }
                else if (node == node->parent->left && parent == parent->parent->right)
                {
                    RightRotation(parent);
                    LeftRotation(grandparent);
                }
                else
                {
                    LeftRotation(parent);
                    RightRotation(grandparent);
                }
            }
        }
    }

    Node<T> *RightRotation(Node<T> node)
    {
        Node<T> *leftChild = node->left;
        node->left = leftChild->right;
        leftChild->right = node;
        return leftChild;
    }

    Node<T> *LeftRotation(Node<T> node)
    {
        Node<T> *rightChild = node->right;
        node->right = rightChild->left;
        rightChild->left = node;
        return rightChild;
    }

    void BottomUp(T key)
    {
        Node<T> *deleteNode = UnsplayedSearch(key);
        Node<T>* parent=deleteNode->parent;
        if(deleteNode->data!=key){
            Splay(deleteNode);
            return;
        }
        if (deleteNode->left == nullptr)
        {
            Transplant(deleteNode, deleteNode->right);
        }
        else if (deleteNode->right == nullptr)
        {
            Transplant(deleteNode, deleteNode->left);
        }
        else
        {
            Node<T> *InorderSuccessor =Successor(deleteNode->right);
            if(InorderSuccessor->parent!=deleteNode){
                Transplant(InorderSuccessor,InorderSuccessor->right);
                InorderSuccessor->right=deleteNode->right;
                InorderSuccessor->right->parent=InorderSuccessor;
            }
            Transplant(deleteNode,InorderSuccessor);
            InorderSuccessor->left=deleteNode->left;
            InorderSuccessor->left->parent=InorderSuccessor;
            delete(deleteNode);
        }
        Splay(parent);
    }

    void BottomUpDelete(T key)
    {
        Node<T> *deleteNode = UnsplayedSearch(key);
        Node<T>* parent=deleteNode->parent;
        if(deleteNode->data!=key){
            Splay(deleteNode);
            return;
        }
        if (deleteNode->left == nullptr)
        {
            Transplant(deleteNode, deleteNode->right);
        }
        else if (deleteNode->right == nullptr)
        {
            Transplant(deleteNode, deleteNode->left);
        }
        else
        {
            Node<T> *InorderSuccessor =Successor(deleteNode->right);
            if(InorderSuccessor->parent!=deleteNode){
                Transplant(InorderSuccessor,InorderSuccessor->right);
                InorderSuccessor->right=deleteNode->right;
                InorderSuccessor->right->parent=InorderSuccessor;
            }
            Transplant(deleteNode,InorderSuccessor);
            InorderSuccessor->left=deleteNode->left;
            InorderSuccessor->left->parent=InorderSuccessor;
            delete(deleteNode);
        }
        Splay(parent);
    }

    void TopDownDelete(T key)
    {
        if(root==nullptr){
            return;
        }
        Node<T>* deleteNode=Search(key);
        if(deleteNode->data!=key){
            Splay(deleteNode);
            return;
        }
        if(root->left==nullptr){
            root=root->right;
        }
        else{
            Node<T>* leftMax=Predecessor(root->left);
            Node<T>* temp=root;
            Node<T>* root=root->left;
            Splay(leftMax);
            root->right=temp->right;
            delete(temp);
        }
        return root;
    }

    Node<T> *Successor(Node<T> *p)
    {
        while (p && p->left != nullptr)
        {
            p = p->left;
        }
        return p;
    }

    Node<T> *Predecessor(Node<T> *p)
    {
        while (p && p->right != nullptr)
        {
            p = p->right;
        }
        return p;
    }

    void Transplant(Node<T> *u, Node<T> *v)
    {
        if (u->parent == nullptr)
        {
            root = v;
        }
        else if (u->parent->left == nullptr)
        {
            u->parent->left = v;
        }
        else
            u->parent->right = v;
        if (v != nullptr)
        {
            v->parent = u->parent;
        }
    }

    Node<T> *Search(T key, Node<T> *currentNode = root, Node<T>* prevNode=nullptr)
    {
        if (currentNode == nullptr)
            return prevNode;
        if (key == currentNode->data)
        {
            Splay(currentNode);
            return currentNode;
        }
        else if (key < currentNode->data)
        {
            return Search(key, currentNode->left,currentNode);
        }
        else
            return Search(key, currentNode->right,currentNode);
    }

    Node<T> *UnsplayedSearch(T key, Node<T> *currentNode = root,Node<T> *prevNode=nullptr)
    {
        if (currentNode == nullptr)
            return prevNode;
        if (key == currentNode->data)
        {
            return currentNode;
        }
        else if (key < currentNode->data)
        {
            return Search(key, currentNode->left,currentNode);
        }
        else
            return Search(key, currentNode->right,currentNode);
    }

    
};

int main(void)
{
}