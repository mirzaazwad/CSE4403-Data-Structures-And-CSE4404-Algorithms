#include<iostream>
#include<queue>
using namespace std;

namespace nonstd{
    template<typename T>class Node{
        public:
        T data;
        Node<T>* parent;
        Node<T>* right;
        Node<T>* left;
        Node(T value){
            data=value;
            left=nullptr;
            right=nullptr;
            parent=nullptr;
        }
    };

    template<typename T>class BinarySearchTree{
        private:
        Node<T>* root=nullptr;

        public:

        void Insert(T key){
            Node<T>* insertNode=new Node<T>(key);
			Node<T>* t=root;
			Node<T>* temp=nullptr;
			while(t!=nullptr){
				temp=t;
				if(insertNode->data < t->data){
					t=t->left;
				}
				else{
					t=t->right;
				}
			}
			insertNode->parent=temp;
			if(temp==nullptr){
				root=insertNode;
			}
			else if(insertNode->data<temp->data){
				temp->left=insertNode;
			}
			else temp->right=insertNode;
		}

        Node<T>* Search(T key,Node<T>* t=nullptr,bool set=false){
            if(!set){
                set=true;
                t=root;
            }
            if(t==nullptr)return nullptr;
            if(key==t->data)return t;
            else if(key<t->data)return Search(key,t->left,true);
            else return Search(key,t->right,true);
        }

        void Inorder(Node<T>* t=nullptr,bool set=false){
            if(t==nullptr){
                if(!set){
                    t=root;
                    set=true;
                    Inorder(t,set);
                }
                return;
            }
			Inorder(t->left,set);
			cout<<t->data<<" ";
			Inorder(t->right,set);
		}

        Node<T>* Predecessor(Node<T>* p){
            while(p && p->right!=nullptr){
                p=p->right;
            }
            return p;
        }

        T InorderPredecessor(){
            return Predecessor(root->left)->data;
        }

        Node<T>* Successor(Node<T>* p){
            while(p && p->left!=nullptr){
                p=p->left;
            }
            return p;
        }

        T InorderSuccessor(){
            return Successor(root->right)->data;
        }

        
        void LevelOrderTraversal(){
            queue<Node<T>*>q,level;
            q.push(root);
            while(!q.empty()){
                while(!q.empty()){
                    cout<<q.front()->data<<" ";
                    if(q.front()->left!=nullptr)level.push(q.front()->left);
                    if(q.front()->right!=nullptr)level.push(q.front()->right);
                    q.pop();
                }
                while(!level.empty()){
                    q.push(level.front());
                    level.pop();
                }
            }
        }

        Node<T>* Delete(T key,Node<T>* t=nullptr,bool set=false){
            Node<T>* temp;
            if(t==nullptr){
                if(!set){
                    t=root;
                    Delete(key,t,true);
                }
                return nullptr;
            }
            if(t->left==nullptr && t->right==nullptr){
                if(t==root){
                    root=nullptr;
                }
                delete t;
                return nullptr;
            }

            if(key<t->data){
                t->left=Delete(key,t->left,true);
            }
            else if(key>t->data){
                t->right=Delete(key,t->right,true);
            }
            else{
                if(Height(t->left)>Height(t->right)){
                    temp=Predecessor(t->left);
                    t->data=temp->data;
                    t->left=Delete(temp->data,t->left,true);
                }
                else{
                    temp=Successor(t->right);
                    t->data=temp->data;
                    t->right=Delete(temp->data,t->right,true);
                }
            }
            return t;
        }

        int Height(Node<T>* p){
            int x,y;
            if(p==nullptr){
                return 0;
            }
            x=Height(p->left);
            y=Height(p->right);
            return x>y?x+1:y+1;
        }


    };

}



int main(void){
    nonstd::BinarySearchTree<int>tree=nonstd::BinarySearchTree<int>();
    int n;
    while(cin>>n,n!=-1){
        tree.Insert(n);
        //Question 1? Why is a number that has a difference of 3 being added here, isnt it the same system as task 1, 88 and 90 has a difference less than 3
        //Question 2? Why does the initial state has 84 missing in the given output
        /*
        Isn't this the right output?
        50 25 75 10 29 60 90 45 80 100 84 88 (initial)
        50 25 75 10 45 60 90 80 100 84 88
        50 45 75 10 60 90 80 100 84 88
        50 45 80 10 60 90 84 100 88
        50 10 80 60 90 84 100 88
        60 10 80 90 84 100 88
        60 10 84 90 88 100
        */

    }
    tree.LevelOrderTraversal();
    cout<<"(initial)"<<endl;
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        tree.Delete(num);
        tree.LevelOrderTraversal();
        cout<<endl;
    }
}