class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> sub = new HashMap<>();
        int count = 0;
        int i = -1;
        int j = -1;
        while(true){
            boolean f1 = false;
            boolean f2 = false;
            // Acquire            
            while(i < s.length() - 1) {
                f1 = true;
                i++;
                char ch = s.charAt(i);
                sub.put(ch, sub.getOrDefault(ch,0)+1);
                if(sub.get(ch) == 2) {
                    break;
                } else {
                    int len = i-j;
                    if(len > count) {
                        count = len;
                    }
                }
            }
            // Release
            while(j < i) {
                f2 = true;
                j++;
                char ch = s.charAt(j);
                sub.put(ch, sub.get(ch)-1);
                if(sub.get(ch) == 1) {
                    break;
                }
            }
            if(f1 == false && f2 == false) {
                break;
            }
        }
        return count;
    }
}