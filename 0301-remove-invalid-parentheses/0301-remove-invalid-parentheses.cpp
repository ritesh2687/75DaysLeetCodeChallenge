class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> answer;
        unordered_set<string> vis;
        queue<string> q;
        q.push(s);
        while (q.size() != 0) {
            int size = q.size();
            bool check = false;
            for (int i =0;i<size;i++) {
                string s = q.front(); q.pop();
                if (vis.count(s)) continue;
                vis.insert(s);
                if (isValid(s)) {
                    check = true;
                    answer.push_back(s);
                } else {
                    int n = s.size();
                    for (int i = 0;i<n;i++) {
                        string newString = s.substr(0,i) + s.substr(i+1,n-i-1);
                        q.push(newString);
                    }
                }
            }
            if (check) return answer;
        }
        return {};
    }
    bool isValid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count <0) return false;
            }
        }
        return count == 0;
    }
};