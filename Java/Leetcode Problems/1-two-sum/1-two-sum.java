// class Solution {
//     public int[] twoSum(int[] nums, int target) {
//         for (int i = 0; i < nums.length - 1; ++i)
//             for (int j = i + 1; j < nums.length; ++j)
//                 if (nums[i] + nums[j] == target) 
//                     return new int[]{i, j};
//         return null;
//     }
// }

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            map.put(nums[i],i);
        }
        
        for(int i = 0; i < nums.length; i++) {
            int temp = target - nums[i];
            if(map.containsKey(temp) && i != map.get(temp)) {
                return new int[]{i,map.get(temp)};
            }
        }
        return null;
    }
}