#include<bits/stdc++.h>
using namespace std;

class WordDictionary {
private:
 vector<WordDictionary*>children;
 bool isEndOfWord;
 int prefix_value;
public:
    WordDictionary():isEndOfWord(false) {
        prefix_value=0;
        children.resize(26);
        fill(children.begin(),children.end(),nullptr);
    }
    
    void addWord(string word) {
        WordDictionary *curr=this;
        curr->prefix_value++;
        for(char &character:word){
            if(!curr->children[character-'a']){
                curr->children[character-'a'] =new WordDictionary();
            }
            curr=curr->children[character-'a'];
            curr->prefix_value++;
        }
        curr->isEndOfWord=true;
    }
    
    bool search(string word) {
        WordDictionary* curr=this;
        int word_len=word.length();
        for (int i=0;i<word_len;i++)
            {
                char character=word[i];
                if(character=='.'){
                    for(auto u:curr->children){
                        if(u && u->search(word.substr(i+1))){
                            return true;
                        }
                    }
                    return false;
                }
                if(curr->children[character-'a']==nullptr){
                    return false;
                }
                curr=curr->children[character-'a'];
            }
            return curr &&  curr->isEndOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(void){

// ["WordDictionary","addWord","addWord","search","search","search","search","search","search"]
// [[],["a"],["a"],["."],["a"],["aa"],["a"],[".a"],["a."]]
    WordDictionary *dictionary=new WordDictionary();
    dictionary->addWord("a");
    dictionary->addWord("a");
    dictionary->search(".");
    dictionary->search("a");
    dictionary->search("aa");
    dictionary->search("a");
    dictionary->search(".a");
    dictionary->search("a.");
}