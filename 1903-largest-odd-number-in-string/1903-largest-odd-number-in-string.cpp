class Solution {
public:
    string largestOddNumber(string num) {
       if (!num.empty()){
        if(num[0]=='0'){
            num.erase(0,1);
        }
        while(!num.empty() && num.back()%2==0){
            num.pop_back();
        }
       } 
       return num;
    }
};