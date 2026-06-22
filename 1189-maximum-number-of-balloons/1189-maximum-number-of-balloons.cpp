class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26,0);

        for(char c:text){
            freq[c-'a']++;
        }

        int maxWords=freq['b'-'a'];
        maxWords=min(maxWords,freq['a'-'a']);
        maxWords=min(maxWords,freq['l'-'a']/2);
        maxWords=min(maxWords,freq['o'-'a']/2);
        maxWords=min(maxWords,freq['n'-'a']);

        return maxWords;
    }
};