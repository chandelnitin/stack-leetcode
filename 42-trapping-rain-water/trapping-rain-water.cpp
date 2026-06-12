class Solution {
public:// kisi bhi bulding ke uper water jama hoga agr uske left ki building or right ki building badi ho . or jma kitna hoga dono bulding ki hight ka minimum minus building height     water+=min(left max,right max)-h[i];




    vector<int> prefixMaxArray(vector<int>&nums){
        vector<int>left(nums.size(),-1);
        int Max=nums[0];
        for(int i=0;i<nums.size();i++){
            if(Max<nums[i]){
              left[i]=nums[i];
               Max=nums[i];
            }
            else{
                left[i]=Max;
            }
        }
        return left;
    }

    vector<int> sufixMaxArray(vector<int>&nums){
         int n=nums.size();
         vector<int>right(n);
         int Max=nums[n-1];
         for(int i=n-1;i>=0;i--){
            if(Max<nums[i]){
                right[i]=nums[i];
                Max= nums[i];
            }
            else{
                right[i]=Max;
            }
         }

         return right;
    }



    int trap(vector<int>& height) {
        vector<int>leftMax= prefixMaxArray(height);
        vector<int>rightMax= sufixMaxArray(height);

        int water=0; int n=height.size();
        for(int i=0;i<n;i++){

           if(height[i]<leftMax[i] && height[i]<rightMax[i]){
            water+=min(leftMax[i],rightMax[i])-height[i];
           }
        }
       
       return water;
    }
};