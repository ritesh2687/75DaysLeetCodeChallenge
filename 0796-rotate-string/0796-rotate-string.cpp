class Solution {
public:
    bool rotateString(string s, string goal) {

///111111111111111111111111111111111111111111111111111111111111111111        
        // string s2 = s + s;
        // // int l=s2.size();
        // int j = 0;
        bool ans = false;

        if(s.size()!=goal.size()){
             return false;
         }
        // for (int i = 0; i < s2.size(); i++) {
        //     if (s2[i] != goal[j]) {
        //         if(j>0){
        //             i=i-j;
        //             j=0;
        //         }
        //         j=0;
        //     } else if (s2[i] == goal[j]) {
                
        //         j++;
        //         cout<<j<<endl;
        //         if(j==goal.size()){
        //             ans=true;
        //             break;
        //        }
        //     }
        // }
/////////////22222222222222222222222222222222222222222222222222222222222
        string t=s;
        for(int i=0;i<s.size();i++){
            reverse(s.begin(),s.end());

            reverse(s.begin(),s.begin()+i);
            reverse(s.begin()+i,s.end());
            if(s==goal) return true;
            s=t;

        }
        

        return ans;
    }
};