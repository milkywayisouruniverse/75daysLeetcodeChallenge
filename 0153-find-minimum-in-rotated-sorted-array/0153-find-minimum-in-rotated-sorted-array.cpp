class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        int mid = 0;

        while(left < right) {
            mid = left + (right - left)/2;

            if(nums[mid] > nums[right]){
                left = mid + 1; // smallest lies in right half
            }

            else{
                 right = mid; // smallest lies in left half but we cannot discard mid as mid could be our ans
            }
        }
        return nums[left];
    }
};