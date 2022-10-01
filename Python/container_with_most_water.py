class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxi = 0
        
        start, end = 0, len(height) - 1
        while start < end :
            vol = min(height[start], height[end]) * (end - start)
            maxi = max(maxi, vol)
            
            if height[start] <= height[end]:
                start += 1
            else:
                end -= 1
                
        return maxi