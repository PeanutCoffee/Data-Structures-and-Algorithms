class Solution {
    public boolean isValid(String s) {
        
        Stack<Character> st = new Stack< >();
        
        for(int i=0;i<s.length();i++) {
            char ch = s.charAt(i);
            if(ch=='(' || ch=='{' || ch=='[') {
                st.push(ch);
            } 
            else if(st.isEmpty()==true){
				return false;
			}
            else if (ch==')' && st.pop()!='(') {
                // boolean val = check(st, '(');
                // return val;
                return false;
            } 
            else if (ch=='}' && st.pop()!='{') {
                // boolean val = check(st, '{');
                // return val;
                return false;
            } 
            else if (ch==']' && st.pop()!='[') {
                // boolean val = check(st, '[');
                // return val;
                return false;
            } 
        }
        return st.isEmpty();
        
    }
    
    static boolean check(Stack<Character> sta, char c) {
        
        if(sta.size()==0 || sta.peek()!= c) {
            return false;
        }
        // if top is the matching bracket of the given bracket pop the bracket and return true;
        else {
            sta.pop();
            return true;
        }
    }
}