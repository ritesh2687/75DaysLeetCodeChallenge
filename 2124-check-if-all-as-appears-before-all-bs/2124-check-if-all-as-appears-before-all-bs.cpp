class Solution {
public:
    bool checkString(string s) {
        int count=0;
        for(char c:s){
          if(c=='b') count=1;
          if(c=='a' && count==1) return  false;
        }
        return true;
    }
};