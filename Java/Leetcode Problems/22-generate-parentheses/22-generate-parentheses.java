class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        find("(", 1, 0, ans, n);
        return ans;
    }
    void find(String curr, int out, int close, List<String> ans, int n) {
        if(curr.length() == 2*n) {
            ans.add(curr);
            return;
        }
        if(out<n)find(curr + "(", out + 1, close, ans, n);
        if(close<out)find(curr + ")", out, close + 1, ans, n);
    }
}