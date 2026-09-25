class Solution {
    set<string> s;

    void dfs(string exp) {
        size_t j = exp.find('}');
        if (j == string::npos) {
            s.insert(exp);
            return;
        }

        size_t i = exp.rfind('{', j);
        string a = exp.substr(0, i);
        string c = exp.substr(j + 1);
        string mid = exp.substr(i + 1, j - i - 1);

        stringstream ss(mid);
        string b;
        while (getline(ss, b, ',')) {
            dfs(a + b + c);
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        s.clear();
        dfs(expression);
        return vector<string>(s.begin(), s.end());
    }
};