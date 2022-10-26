#include <iostream>
using namespace std;

namespace __self
{

    class Node
    {
    public:
        bool terminal; // means endmark
        Node *next[26];
        int prefix_value;
        Node()
        {
            prefix_value = 0;
            terminal = false;
            for (int i = 0; i < 26; i++)
            {
                next[i] = nullptr;
            }
        }
    };

    class Trie
    {
    private:
        Node *root;

    public:
        Trie()
        {
            root=new Node();
        }

        void insert(string word)
        {
            Node *curr = root;
            root->prefix_value++;//Count of words in a dictionary
            for (char &character : word)
            {
                int id = character - 'a';
                if (curr->next[id] == nullptr)
                {
                    curr->next[id] = new Node();
                }
                curr = curr->next[id];
                curr->prefix_value++;
            }
            curr->terminal=true;
        }

        bool search(string word)
        {
            Node *curr = root;
            for (char character : word)
            {
                int id = character - 'a';
                if (curr->next[id] == nullptr)
                {
                    return false;
                }
                curr = curr->next[id];
            }
            return curr->terminal;
        }

        bool isEmpty()
        {
            for (int i = 0; i < 26; i++){
                if (root->next[i]!=nullptr)return false;
            }
            return true;
        }

        bool isSubstreeEmpty(Node* node){
            for (int i = 0; i < 26; i++){
                if (node->next[i]!=nullptr)return false;
            }
            return true;
        }


    };
}

int main(void)
{
    __self::Trie trie=__self::Trie();
    string s;cin>>s;
    trie.insert(s);
    cin>>s;
    trie.insert(s);
    cin>>s;
    trie.insert(s);
    cin>>s;
    trie.insert(s);
    cin>>s;
    trie.insert(s);
    if(trie.search("dog")){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
}