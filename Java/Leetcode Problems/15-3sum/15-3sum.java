class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        // sort the array
        Arrays.sort(nums);
        List<List<Integer>> out = new ArrayList<>();
        
        //start from 1st position, assign it to i then assign sum equals 0 - 1st element from array
        for(int i = 0; i < nums.length - 2; i++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int low = i + 1;
                int high = nums.length - 1;
                int sum = 0 - nums[i];

                // now find 2sum == sum
                while(low < high) {
                    if(nums[low] + nums[high] == sum) {
                        out.add(Arrays.asList(nums[i], nums[low], nums[high]));
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(low < high && nums[high] == nums[high-1]) high--;
                        low++;
                        high--;
                    } else if(nums[low] + nums[high] < sum)
                        low++;
                    else
                        high--;
                }
            }
        }
        return out;
    }
}