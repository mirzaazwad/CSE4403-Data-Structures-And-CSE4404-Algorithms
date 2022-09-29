#include<iostream>
using namespace std;

namespace nonstd{

    template<typename T>class Node{
        public:
        Node<T>* left;
        Node<T>* right;
        Node<T>* parent;
        T data;
        int height;
        Node(T value){
            data=value;
            left=right=parent=nullptr;
        }

        void setHeight(int h){
            height=h;
        }

    };

    template<typename T>class AVLTree{
        private:
        Node<T>* root=nullptr;
        public:

        void Insert(T key){
            if(root==nullptr){
                root=Insert(root,key);
            }
            Insert(root,key);
        }

        Node<T>* Insert(Node<T>* p,T key){
            Node<T>* t=nullptr;
            if(p==nullptr){
                t=new Node<T>(key);
                t->setHeight(1);//we are starting height with 1 although we logically do it with 0
                return t;
            }
            if(key<p->data){
                p->left=Insert(p->left,key);
            }
            else if(key>p->data){
                p->right=Insert(p->right,key);
            }
            p->height=NodeHeight(p); 
            if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1){
                //cout<<"Left Roation Performed"<<endl;
                return LLRotation(p);
            }
            else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1){
                //cout<<"LR Performed"<<endl;
                return LRRotation(p);
            }
            else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1){
                //cout<<"Right Roation Performed"<<endl;
                return RRRotation(p);
            }
            else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1){
                //cout<<"RL Performed"<<endl;
                return RLRotation(p);
            }
            return p;
        }

        Node<T>* LLRotation(Node<T>* p){
            Node<T>* pl=p->left;
            Node<T>* plr=p->left->right;
            pl->right=p;
            p->left=plr;
            p->height=NodeHeight(p);
            pl->height=NodeHeight(pl);

            if(p==root){
                root=pl;
            }
            return pl;
        }

        Node<T>* LRRotation(Node<T>* p){
            Node<T> *pl=p->left;
            Node<T> *plr=pl->right;

            pl->right=plr->left;
            p->left=plr->right;
            plr->left=pl;
            plr->right=p;

            pl->height=NodeHeight(pl);
            p->height=NodeHeight(p);
            plr->height=NodeHeight(plr);
            if(root==p)
            root=plr;
            return plr;
        }

        Node<T>* RRRotation(Node<T>* p){
            Node<T>* pr=p->right;
            Node<T>* prl=p->right->left;
            pr->left=p;
            p->right=prl;
            p->height=NodeHeight(p);
            pr->height=NodeHeight(pr);

            if(p==root){
                root=pr;
            }
            return pr;
        }

        Node<T>* RLRotation(Node<T>* p){
            Node<T> *pr=p->right;
            Node<T> *prl=pr->left;

            pr->left=prl->right;
            p->right=prl->left;
            prl->right=pr;
            prl->left=p;
            
            pr->height=NodeHeight(pr);
            p->height=NodeHeight(p);
            prl->height=NodeHeight(prl);
            if(root==p)
            root=prl;
            return prl;
        }

        int BalanceFactor(Node<T>* p){
            int hl,hr;
            hl= p && p->left?p->left->height:0;
            hr= p && p->right?p->right->height:0;
            return hl-hr;
        }

        int NodeHeight(Node<T>* p){
            int hl,hr;
            hl= p && p->left?p->left->height:0;
            hr= p && p->right?p->right->height:0;
            return hl>hr?hl+1:hr+1;
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

        /*DEBUG CODE START*/
        // T getRootValue(){
        //     return root->data;
        // }

        // Node<T>* getRoot(){
        //     return root;
        // }
        /*DEBUG CODE END*/

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
        //DEBUGGING FEATURE
        void GetRoot(){
            cout<<root->data<<endl;
        }

    };
}

int main(void){
    nonstd::AVLTree<int> avl;
    avl.Insert(10);
    // avl.GetRoot();
    avl.Insert(5);
    avl.Insert(7);
    // avl.GetRoot();
    return 0;
}