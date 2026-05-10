class Solution {
public:
    vector<string> ans;
    void solve(string op, int open, int close, int n){
        if(op.length()==2*n){
            ans.push_back(op);
            return;
        }
        if(open < n){
            solve(op+"(",open+1,close,n);
        }

        if(close < open){
            solve(op+")",open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve("",0,0,n);
        return ans;
    }
};