class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans=[]
        for i in nums:
            j=list(str(i))
            for k in j:
                ans.append(int(k))
        return ans        
        