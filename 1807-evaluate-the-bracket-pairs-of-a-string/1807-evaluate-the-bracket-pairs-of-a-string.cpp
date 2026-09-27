class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {


       unordered_map<string,string> dict;
       for(const auto& pair : knowledge){
        dict[pair[0]]=pair[1];
       } 
       string result="";
       string current_key="";
       bool inside_bracket =false;


       for(char c : s){
        if (c=='('){
            inside_bracket=true;
            current_key="";
        }
        else if(c==')'){
            inside_bracket=false;
            if(dict.find(current_key)!=dict.end()){
                result+=dict[current_key];

            }
            else{
                result+='?';
            }

        }else{
            if(inside_bracket){
                current_key+=c;
            }
            else{
                result+=c;
            }
        }
       }
       return result;
    }
};