class Solution {
    public double findMaxAverage(int[] nums, int k) {
double max=0,sum=0;
        int n=nums.length;
        for(int i=0;i<k&&i<n;i++){
            sum+=nums[i];
        }
        max=sum/k;
        for(int i=k;i<n;i++){
            sum=sum-nums[i-k]+nums[i];
            max=Math.max(max,sum/k);
        }
        return max;
    }
}