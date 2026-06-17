class Solution {
    vector<string> answer;
public:
    vector<string> letterCasePermutation(string s) {
        find(s,0,"");
        return answer;
    }
    void  find(string s,int i,string ans) {
        if (i == s.size()) {
            answer.push_back(ans);
            return;
        }
        if (isalnum(s[i]) && !isdigit(s[i])) {
            find(s,i+1,ans + (char)toupper(s[i]));
            find(s,i+1,ans + (char)tolower(s[i]));
        } else {
            find(s,i+1,ans+s[i]);
        }
    }
};