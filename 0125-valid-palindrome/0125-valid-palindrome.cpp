class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned="";
        
        for(char c:s){
            if(isalnum(c))
            cleaned+=tolower(c);
        }
        int l=0,r=cleaned.length()-1;


        while(l<r){
            if(cleaned[l]!=cleaned[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};