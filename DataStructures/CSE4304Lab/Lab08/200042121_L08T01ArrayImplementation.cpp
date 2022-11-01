#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    int trie[300005][50];
    int id = 1;
    int endmark[300005];
    int pre[300005];
    Trie()
    {
        memset(trie, 0, sizeof(trie));
        memset(endmark, 0, sizeof(endmark));
        memset(pre, 0, sizeof(pre));
        cout<<"Object Created"<<endl;
    }

    void insert(string word)
    {
        int row = 1;
        for (int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - 'a';
            if (trie[row][ch] == 0)
            {
                trie[row][ch] = ++id;
            }
            row = trie[row][ch];
            pre[row]++;
        }
        endmark[row] = 1;
        cout<<"Word Added"<<endl;
    }

    bool startsWith(string prefix)
    {
        int row = 1;
        for (int i = 0; i < prefix.size(); i++)
        {
            int ch = prefix[i] - 'a';
            if (trie[row][ch] == 0)
                return false;
            row = trie[row][ch];
        }
        return (pre[row] >= 1);
    }

    bool search(string word)
    {
        int row = 1;
        for (char &character : word)
        {
            if (character == '.')
            {
                for (int id = 0; id < 26; id++)
                {
                    if (trie[row][id]!=0)
                    {
                        character = (id + 'a');
                        return search(word);
                    }
                }
            }
            else
            {
                int id = character - 'a';
                if (trie[row][id]==0)
                {
                    return false;
                }
                row=trie[row][id];
            }
        }
        return (endmark[row] == 1);
    }

    void searchFound(string word)
    {
        if (search(word))
        {
            cout << "Word Found" << endl;
        }
        else
        {
            cout << "Word Not Found" << endl;
        }
    }
};

int main(void)
{
     Trie* dictionary=new Trie();
    dictionary->insert("bad");
    dictionary->insert("dad");
    dictionary->insert("mad");
    dictionary->searchFound("pad");
    dictionary->searchFound("bad");
    dictionary->searchFound(".ad");
    dictionary->searchFound("b..");
}
