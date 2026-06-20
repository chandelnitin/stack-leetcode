class Solution {
public:// pivot elelemnt ke left me sbhi elemnt chote or right me sabhi bad element hai
    int findPivotIndex(vector<int>&nums,int left,int right){
        int i=left-1;
        int j=left;
        int pivot=nums[right];
        while(j<right){
            if(nums[j]>pivot){
                swap(nums[++i],nums[j]);
            }
            j++;
        }

        swap(nums[i+1],nums[right]);
        return i+1;
    }
    int findKthLargest(vector<int>& nums, int k) {
         int left =0;int right=nums.size()-1;
         int pivotIndex=findPivotIndex(nums,left,right);
         while(true){
            if(pivotIndex==k-1) break;
            else if(pivotIndex<k-1){
               left=pivotIndex+1;
               pivotIndex= findPivotIndex(nums,left,right);
            }
            else{
                right=pivotIndex-1;
               pivotIndex= findPivotIndex(nums,left,right);
            }
         }  

         return nums[pivotIndex];
    }
};