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

        void search(string word){
            int len=word.length();
            deque<int>dotpos;
            for(int i=0;i<len;i++){
                if(word[i]=='.'){
                    dotpos.push_back(i);
                }
            }
            if(!recursiveWordAdd(dotpos,word)){
                cout<<"Word Not Found"<<endl;
            }
        }

        bool recursiveWordAdd(deque<int>dotpos,string word){
            if(dotpos.size()==0){
                if(SearchWord(word)){
                    cout<<"Word Found"<<endl;
                    return true;
                }
            }
            for(auto u:dotpos){
                for(int id=0; id < 26; id++){
                    word[u]=id+'a';
                    deque<int>temp=dotpos;
                    int ix=temp.front();
                    temp.pop_front();
                    if(recursiveWordAdd(temp,word)){
                        return true;
                    }
                    temp.push_front(ix);
                }
            }
            return false;
        }


    };
}


int main(void){
    __self::Trie dictionary;
    dictionary.insert("bad");
    dictionary.insert("dad");
    dictionary.insert("mad");
    dictionary.search("pad");
    dictionary.search("bad");
    dictionary.search(".ad");
    dictionary.search("b..");
}