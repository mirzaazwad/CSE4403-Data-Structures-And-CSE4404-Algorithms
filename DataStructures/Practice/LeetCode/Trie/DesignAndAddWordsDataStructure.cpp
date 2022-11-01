#include<bits/stdc++.h>
using namespace std;

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

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
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
    
    bool search(string word) {
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
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(void){

}