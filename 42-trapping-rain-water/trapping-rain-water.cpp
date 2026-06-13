// class Solution {
// public:// kisi bhi bulding ke uper water jama hoga agr uske left ki building or right ki building badi ho . or jma kitna hoga dono bulding ki hight ka minimum minus building height     water+=min(left max,right max)-h[i];




//     vector<int> prefixMaxArray(vector<int>&nums){
//         vector<int>left(nums.size(),-1);
//         int Max=nums[0];
//         for(int i=0;i<nums.size();i++){
//             if(Max<nums[i]){
//               left[i]=nums[i];
//                Max=nums[i];
//             }
//             else{
//                 left[i]=Max;
//             }
//         }
//         return left;
//     }

//     vector<int> sufixMaxArray(vector<int>&nums){
//          int n=nums.size();
//          vector<int>right(n);
//          int Max=nums[n-1];
//          for(int i=n-1;i>=0;i--){
//             if(Max<nums[i]){
//                 right[i]=nums[i];
//                 Max= nums[i];
//             }
//             else{
//                 right[i]=Max;
//             }
//          }

//          return right;
//     }



//     int trap(vector<int>& height) {
//         vector<int>leftMax= prefixMaxArray(height);
//         vector<int>rightMax= sufixMaxArray(height);

//         int water=0; int n=height.size();
//         for(int i=0;i<n;i++){

//            if(height[i]<leftMax[i] && height[i]<rightMax[i]){
//             water+=min(leftMax[i],rightMax[i])-height[i];
//            }
//         }
       
//        return water;
//     }
// };












class Solution {
public:
    // Two Pointer Approach

// Water kisi bhi building par depend karta hai:
//
// water = min(leftMax, rightMax) - height[i]
//
// Yaha leftMax = current building ke left me sabse badi height
// aur rightMax = current building ke right me sabse badi height.
//
// Hum do pointers rakhte hain:
// left -> start par
// right -> end par
//
// Sath hi leftMax aur rightMax maintain karte hain.
//
// Sabse important observation:
//
// Agar leftMax < rightMax hai, to current left building ka answer
// isi waqt nikal sakte hain.
//
// Reason:
//
// Water hamesha min(leftMax, rightMax) par depend karta hai.
// Aur jab leftMax chhota hai, to minimum already leftMax hi hoga.
//
// Is situation me rightMax ki exact value jaanne ki zarurat nahi hai.
// Bas itna pata hona chahiye ki right side me koi wall maujood hai
// jo leftMax se badi hai.
//
// Chahe rightMax = 8 ho, 20 ho ya 100 ho,
// min(leftMax, rightMax) fir bhi leftMax hi rahega.
//
// Isliye current left building ke liye:
//
// water = leftMax - height[left]
//
// confidently calculate kar sakte hain aur left pointer ko aage
// badha sakte hain.
//
// Isi tarah agar rightMax <= leftMax hai,
// to current right building ka answer isi waqt nikal sakte hain.
//
// Kyuki ab minimum rightMax hi hoga.
// Left side me kitni bhi badi wall aa jaye,
// water level rightMax se upar nahi ja sakta.
//
// Isliye:
//
// water = rightMax - height[right]
//
// calculate karke right pointer ko piche le aate hain.
//
// Short Intuition:
//
// Jis side ka max chhota hota hai wahi bottleneck hota hai.
// Isliye us side ka water bina kisi additional information ke
// calculate kiya ja sakta hai.
    int trap(vector<int>& height) {
        int left=1; int n=height.size();
        int right=n-2;
        int lMax=height[0]; int rMax= height[n-1];
        int water=0;
        while(left<=right){
            if(lMax<=rMax){  // left pointer ke liye watertrap
                if(height[left]<lMax){
                    water+=lMax-height[left];
                }
                lMax=max(lMax,height[left]);
                left++;
            }
            else{ // right pointer ke liye water trap
                if(height[right]<rMax){
                    water+=rMax-height[right];
                }
                rMax=max(rMax,height[right]);
                right--;
            }
        }

        return water;
    }
};


















