class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        maxSumsoFar = nums[0]
        currSum = nums[0]
        for i in range(1, len(nums)):

            if(currSum < 0): 
             currSum = 0

            currSum = currSum + nums[i];        

            if (currSum > maxSumsoFar):
             maxSumsoFar = currSum
        
        return maxSumsoFar