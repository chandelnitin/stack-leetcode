// class Solution {
// public: // brute force  // tLE TC= O(n-k)*k
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int>ans; int n=nums.size();
//         for(int i=0;i<=n-k;i++){
//             int Max=nums[i];
//             for(int j=i;j<i+k;j++){
//               Max=max(Max,nums[j]);
//             }
//             ans.push_back(Max);
//         }

//         return ans;
//     }
// };







class Solution {
public: // brute force  // tLE TC= O(n-k)*k
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans; int n=nums.size();
        deque<int>dq; // store index of the nums array
        for(int i=0;i<n;i++){
           while(!dq.empty() && dq.front()<=i-k ){// check window valid bhi hai matlb k 
                dq.pop_front();                                
           }

           // decreasing deque maintain krenge .
           // jisse max element front pr hoga
           //{3,2,4} ab isme max element  hai to 3 2 ko pop krenge kunki ane wali window
           // me 3 and 2 kabhi bhi maximum nhi ho sakte {3,2,4,x} // ya to 4 max hoga
           // x maxi hoga aane wali window me . or agr nums[i] smaller hai to isko dq
           // me insert krenge kuki {3,2,4} windo esi hai or nums[i] =1 to 1 ko add krenge
           // window me kuki agr {3,2,4,1,-1,-2} array ese hai to 1 maxi hoga {1,-1,-2}
           // is window ke liye is liye 1 ko ignore nhi kr sakte
           while(!dq.empty() && nums[dq.back()]<=nums[i]){
               dq.pop_back();
           }

           dq.push_back(i);

            if(i>=k-1){ // jb meri window bna jaye kuki jb window ka size k ke equal ho
                ans.push_back(nums[dq.front()]); 
            }
                                   
        }

        return ans;
    }
};