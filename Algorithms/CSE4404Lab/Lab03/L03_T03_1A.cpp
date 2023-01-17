/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
  vector<vector<int>> levelOrder(Node *root)
  {
    queue<Node *> q;
    q.push(root);
    map<int, int> level;
    if (root == nullptr)
    {
      return {};
    }
    level[root->val] = 0;
    map<int, vector<int>> level_member;
    level_member[level[root->val]].push_back(root->val);
    while (!q.empty())
    {
      Node *temp = q.front();
      q.pop();
      for (auto u : temp->children)
      {
        if (u == nullptr)
          continue;
        level[u->val] = level[temp->val] + 1;
        level_member[level[u->val]].push_back(u->val);
        q.push(u);
      }
    }
    vector<vector<int>> ans;
    for (auto u : level_member)
    {
      vector<int> tmp;
      for (auto v : u.second)
      {
        tmp.push_back(v);
      }
      ans.push_back(tmp);
    }
    return ans;
  }
};