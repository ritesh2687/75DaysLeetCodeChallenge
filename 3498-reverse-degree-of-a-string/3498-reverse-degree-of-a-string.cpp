class Solution {
public:
    int reverseDegree(string s) {
    int n = s.length();
    int sum=0;
    for(int i=0;i<n;i++){
        s[i]=toupper(s[i]);
        cout<<91-s[i];
        sum+=(i+1)*(91-s[i]);
        cout<<sum;
    }  
    return sum;
    }
};