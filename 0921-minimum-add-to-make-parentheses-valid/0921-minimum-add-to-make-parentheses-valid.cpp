class Solution {
public:
    int minAddToMakeValid(string s) {
        int o_b=0;
        int r_b=0;
        int c_b=0;
        int ans=0;
        for(char c :s){
            if(c== '('){
                o_b++;
            }
            else {
                o_b--;
                c_b=o_b;
                if(c_b<0){
                    r_b++;
                    o_b=0;
                }
             
            }
               cout<<o_b;
                cout<<r_b;
        }
        return abs(r_b+o_b);
    }
};