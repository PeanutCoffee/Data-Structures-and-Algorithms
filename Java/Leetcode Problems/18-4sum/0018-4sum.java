class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;
        if(n < 4)
            return res;
        
        Arrays.sort(nums);
        
        for(int i = 0; i < n - 3; i++) {
            if (target <= 0 && nums[i] > 0) break;
            // handle duplicates
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            
            for(int j = i + 1; j < n - 2; j++) {
                // handle duplicates
                if(j != i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                
                int left = j + 1;
                int right = n - 1;
                
                
                while(left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        List<Integer> out = new ArrayList<>();
                        out.add(nums[i]);
                        out.add(nums[j]);
                        out.add(nums[left]);
                        out.add(nums[right]);
                        
                        res.add(out);
                        
                        left++;
                        right--;
                        
                        // handle duplicates
                        while(left < right && nums[left] == nums[left - 1]){
                            left++;
                        }
                        // handle duplicates
                        while(left < right && nums[right] == nums[right + 1]){
                            right--;
                        }
                    }
                }
            }
        }
        return res;
    }
}