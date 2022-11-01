#include<bits/stdc++.h>
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
            cout<<"Object Created"<<endl;
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
            cout<<"Word Added"<<endl;
        }

        bool SearchWord(string word)
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

        bool search(string word){
            Node *curr = root;
            for (char &character : word)
            {
                if(character=='.'){
                    for(int id=0;id<26;id++){
                        if(curr->next[id]!=nullptr){
                            character=(id+'a');
                            return search(word);
                        }
                    }
                }
                else{
                    int id = character - 'a';
                    if (curr->next[id] == nullptr)
                    {
                        return false;
                    }
                    curr = curr->next[id];
                }
            }
            return curr->terminal;
        }

        void searchFound(string word){
            if(search(word)){
                cout<<"Word Found"<<endl;
            }
            else{
                cout<<"Word Not Found"<<endl;
            }
        }


    };
}


int main(void){
    __self::Trie dictionary;
    dictionary.insert("bad");
    dictionary.insert("dad");
    dictionary.insert("mad");
    dictionary.searchFound("pad");
    dictionary.searchFound("bad");
    dictionary.searchFound(".ad");
    dictionary.searchFound("b..");
}