class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int>s;
        queue<int>q;
        for(int i=0;i<students.size();i++)q.push(students[i]);
        for(int i=sandwiches.size()-1;i>=0;i--)s.push(sandwiches[i]);
        int n=sandwiches.size();
        int count=0;
        while(!s.empty()){
            if(s.top()==q.front()){
                s.pop();
                q.pop();
                n--;
                count=0;
            }
            else{
                int value=q.front();
                q.pop();
                q.push(value);
                count++;
            }
            if(count==n)break;
        }
        return count;
    }
};
