class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int countTraget=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target){
                    countTraget++;
                }

                int subArrayLength=j-i+1;
                if(countTraget>subArrayLength/2){
                    ans++;
                }
            }
        }

        return ans;
    }
};