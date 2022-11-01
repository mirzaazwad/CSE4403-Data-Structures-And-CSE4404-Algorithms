#include <iostream>
using namespace std;

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
    }

    bool search(string word)
    {
        int row = 1;
        for (int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - 'a';
            if (trie[row][ch] == 0)
                return false;
            row = trie[row][ch];
        }
        return (endmark[row] == 1);
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

    void CurrentPosition(string word, int &tmp)
    {
        int row = 1;
        for (char character : word)
        {
            int id = character - 'a';
            if (trie[row][id] == 0)
            {
                tmp = -1;
                return;
            }
            row = trie[row][character - 'a'];
        }
        tmp = row;
    }

    void suggestions(int &row, string word, vector<string> &result)
    {
        if (result.size() == 3)
        {
            return;
        }
        if (row > id)
        {
            return;
        }
        if (endmark[row] == 1)
        {
            result.push_back(word);
        }

        for (int ch = 0; ch < 26; ch++)
        {
            if (trie[row][ch] != 0 && row <= id)
            {
                word.push_back(ch + 'a');
                int temp = row;
                row = trie[row][ch];
                suggestions(row, word, result);
                row = temp;
                word.pop_back();
            }
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Program
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        Trie *trie = new Trie();
        vector<vector<string>> res;
        for (string s : products)
        {
            trie->insert(s);
        }
        string curr_word = "";
        for (char c : searchWord)
        {
            curr_word.push_back(c);
            int curr;
            trie->CurrentPosition(curr_word, curr);
            vector<string> ans;
            if(curr!=-1)trie->suggestions(curr, curr_word, ans);
            res.push_back(ans);
        }
        return res;
    }
};

int main(void)
{
    string s;
    vector<string> products;
    while (cin >> s)
    {
        products.push_back(s);
    }
    string searchWord;
    searchWord = products.back();
    products.pop_back();
    Program program;
    vector<vector<string>> res = program.suggestedProducts(products, searchWord);
    for (auto u : res)
    {
        for (string s : u)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}