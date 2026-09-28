class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int max_c=0;
        for(int c:s){
            if(c=='(') count++;
            else if(c==')') count--;
            max_c=max(max_c,count);
        }
        return max_c;
    }
};