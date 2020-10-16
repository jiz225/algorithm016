class Solution {
public:
    string path;
    vector<string> combs;
    vector<string> dict = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void collectPath(string digits, int pos){
        if(pos == digits.size()){
            combs.push_back(path);
            return;
        }
        int idx = digits[pos] - '0';
        for(int i = 0;i < dict[idx].size(); i++){
            path.push_back(dict[idx][i]);
            collectPath(digits, pos+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return combs;
        }
        collectPath(digits, 0);
        return combs;
    }
};
