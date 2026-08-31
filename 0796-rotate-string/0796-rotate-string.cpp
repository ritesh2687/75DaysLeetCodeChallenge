class Solution {
public:
    bool rotateString(string s, string goal) {
        string s2 = s + s;
        // int l=s2.size();
        int j = 0;
        bool ans = false;

        if(s.size()!=goal.size()){
            return false;
        }
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] != goal[j]) {
                if(j>0){
                    i=i-j;
                    j=0;
                }
                j=0;
            } else if (s2[i] == goal[j]) {
                
                j++;
                cout<<j<<endl;
                if(j==goal.size()){
                    ans=true;
                    break;
               }
            }
        }
        

        return ans;
    }
};