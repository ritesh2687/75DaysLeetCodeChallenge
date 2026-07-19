class Solution {
public:
    string smallestSubsequence(string s) {
    
    vector<int> lastIdx(26,0);
    vector<bool> check(26,false);

    for (int i=0;i<s.size();i++){
        lastIdx[s[i]-'a']=i;
    }

    string stk="";

    for(int i=0;i<s.size();i++){
        char ch=s[i];

        if(check[ch-'a']) continue;

        while(!stk.empty()
        && stk.back()>ch
        && lastIdx[stk.back()-'a']>i){
            check[stk.back()-'a']=false;
            stk.pop_back();
        }
        stk.push_back(ch);
        check[ch-'a']=true;
    }

    return stk;

    }
};