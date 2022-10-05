

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

public class StringTechniques {
    public static void main(String[] args) {

    }
    //Easy https://leetcode.com/problems/longest-common-prefix/
    public String longestCommonPrefix(String[] strs) {
        String res = "";
        //Arrays.sort(strs);
        for(int i = 0; i < strs[0].length();i++){
            char c = strs[0].charAt(i);
            for(int j = 1;j<strs.length;j++){
                if(strs[j].length() <= i || strs[j].charAt(i) != c) return res;
            }
            res += c;
        }
        return res;
    }

    //Medium https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
    public int strStr(String haystack, String needle) {
        if(needle.length() < 1 || needle.length() > haystack.length()) return -1;
        for(int i =0 ; i < haystack.length();i++){
            if(haystack.charAt(i) == needle.charAt(0)){
                if(helper(i, 0, haystack, needle)) return i;
            }

        }
        return -1;
    }

    public boolean helper(int i , int j, String s1, String s2){
        while(j<s2.length()){
            if(i >= s1.length()) return false;
            if(s1.charAt(i) != s2.charAt(j)) return false;
            i++;
            j++;
        }
        return true;
    }

    //Medium  https://leetcode.com/problems/construct-smallest-number-from-di-string/
    public String smallestNumber(String pt) {
        StringBuilder str = new StringBuilder();
        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(1,2,3,4,5,6,7,8,9));
        char[] cr = pt.toCharArray();

        int j=0;
        for(int i = 0; i < cr.length; i++){
            if(cr[i] == 'I'){
                str.append(arr.get(0));
                arr.remove(0);
            }else{
                int count = 0;
                j = i;
                while(j < cr.length && cr[j] == 'D'){
                    j++;
                    count++;
                }
                for(int a = count;a > 0;a--){
                    str.append(arr.get(a));
                    arr.remove(a);
                }
                i = j-1;


            }


        }
        if(cr[cr.length-1] == 'I' || j >= cr.length){
            str.append(arr.get(0));
        }else{
            str.append(arr.get(1));
        }
        return str.toString();
    }


    // Easy https://leetcode.com/problems/valid-parentheses/
    //Short soln 3ms
    // Note if you dont use stack and use character array then the complexity is 0ms
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (char c : s.toCharArray()) {
            if (c == '(')
                stack.push(')');
            else if (c == '{')
                stack.push('}');
            else if (c == '[')
                stack.push(']');
            else if (stack.isEmpty() || stack.pop() != c)
                return false;
        }
        return stack.isEmpty();
    }
    // Normal Soln
    // 6ms soln
//     public boolean isValid(String s) {
//         if(s.length()%2 != 0){
//             return false;
//         }
//         Stack<Character> st = new Stack<>();
//         HashMap<Character, Character> h = new HashMap<>();
//         h.put(')', '(');
//         h.put(']', '[');
//         h.put('}', '{');

//         // for(int i = 0;i<s.length();i+=2){
//         //     char c = s.charAt(i);
//         //     char ch = s.charAt(i+1);
//         //     if(h.containsKey(ch) && c != h.get(ch)) return false;
//         // }

//         for(int i = 0;i<s.length();i++){
//             char c = s.charAt(i);
//             if(h.containsValue(c)){
//                 st.push(c);
//             }else{
//                if(st.isEmpty() || st.pop() != h.get(c)){

//                    return false;
//                }
//             }
//         }

//         return st.isEmpty();
//     }

    //Easy https://leetcode.com/problems/valid-anagram/
    public boolean isAnagram(String s, String t) {
        int[] alp = new int[26];
        for (int i = 0; i < s.length(); i++)
            alp[s.charAt(i) - 'a']++;
        for (int i = 0; i < t.length(); i++)
            alp[t.charAt(i) - 'a']--;
        for (int i=0;i<26;i++)
            if (alp[i] != 0)
                return false;
        return true;
//

//Another way More Time Complexity
//         if(s.length() != t.length()) return false;
//         HashMap<Character, Integer> hm = new HashMap<>();
//         for(int i = 0;i<s.length();i++){
//             char c = s.charAt(i);
//             hm.put(c, hm.getOrDefault(c, 0) + 1);

//         }
//         for(int i = 0;i<t.length();i++){
//             char c = t.charAt(i);

//             if(hm.containsKey(c) == false){
//                 return false;
//             }else if(hm.get(c) == 1){
//                 hm.remove(c);
//             }else{
//                  hm.put(c, hm.get(c) - 1);
//             }
//         }

//         return hm.size() == 0;

    }
}
