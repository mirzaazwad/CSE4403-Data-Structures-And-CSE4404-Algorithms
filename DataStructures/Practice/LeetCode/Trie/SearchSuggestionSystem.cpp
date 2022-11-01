#include <bits/stdc++.h>
using namespace std;

    class Node
    {
    public:
        bool terminal; // means endmark
        Node *next[26];
        Node *parent;
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
                curr->next[id]->parent=curr;
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

        Node* CurrentPosition(string word)
        {
            Node *curr = root;
            for (char character : word)
            {
                int id = character - 'a';
                if (curr->next[id] == nullptr)
                {
                    return nullptr;
                }
                curr = curr->next[id];
            }
            return curr;
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




        vector<string> suggestions(Node *curr,string word,vector<string>& result){
           if(result.size()==3){
            return;
           }
           if(curr->terminal){
                result.push_back(word);
           }

           for(int id=0;id<26;id++){
                if(curr->next[id]!=nullptr){
                    word.push_back(id+'a');
                    suggestions(curr->next[id],word,result);
                    word.pop_back();
                }
           }
        }

    };

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie=Trie();
        vector<vector<string>>res;
        for(string s:products){
            trie.insert(s);
        }
        string curr_word="";
        for(char c:searchWord){
            curr_word.push_back(c);
            Node *curr=trie.CurrentPosition(curr_word);
            vector<string>ans;
            res.push_back(trie.suggestions(curr,curr_word,ans));
        }
        return res;
    }
};

int main(void)
{
   
}