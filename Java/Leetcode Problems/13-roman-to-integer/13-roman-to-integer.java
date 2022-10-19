class Solution {
    public int romanToInt(String s) {
        int len = s.length();
        HashMap<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
        int sum = 0;
        for(int i = len - 1; i >= 0; i--) {
            char ch = s.charAt(i);
            int num = map.get(ch);
            sum += num;
        }
        
        for(int i = len - 1; i >= 1; i--) {
            char ch1 = s.charAt(i);
            char ch2 = s.charAt(i-1);
            if((ch1 == 'V' || ch1 == 'X' || ch1 == 'L' || ch1 == 'C' || ch1 == 'D' || ch1 == 'M') && ch2 == 'I')
                sum -= 2;
            if((ch1 == 'L' || ch1 == 'C' || ch1 == 'D' || ch1 == 'M') && ch2 == 'X')
                sum -= 20;
            if((ch1 == 'D' || ch1 == 'M') && ch2 == 'C')
                sum -= 200;
        }
        return sum;
    }
}