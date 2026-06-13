class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr) {
        stack<int> st; // maintain decreasing stack of index
        int n=arr.size();
        vector<int> ans(n, n);
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }



    vector<int> previousGreaterElement(vector<int>&arr){
        stack<int>st;  // maintain decreasing monotonic stack
        vector<int>ans(arr.size(),-1); 
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i]){
                ans[st.top()]=i;  // arr[i] apne right ke jitne bhi elelent se bada hai unke index pr arr[i]] dal so
                st.pop();
            }
            
            st.push(i);
        }
        return ans;
    }





    vector<int> nextSmallerElement(vector<int>&arr){
        stack<int>st; // maintaing decreasing stack of indexs
        int n=arr.size();
        vector<int>ans(n,n);
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                ans[st.top()]=i; // arr[i] ke left me jitne bhi element arr[i] se bade hai unke liye arr[i] smaller element hoga isliye hmne index strore kiya . jisse un sbhi element ke index pr arr[i] dal ske
                st.pop();
            }
            
            st.push(i);
        }
        
        return ans;
    }




    vector<int> previousSmallerElement(vector<int>&arr){
        stack<int>st; // maintaing increasing stack
        vector<int>ans(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[i]<arr[st.top()]){
                ans[st.top()]=i;
                st.pop();
            }
            
            st.push(i);
        }
        
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        vector<int> NGE = nextGreaterElement(nums);
        vector<int> PGE = previousGreaterElement(nums);
        vector<int> NSE = nextSmallerElement(nums);
        vector<int> PSE = previousSmallerElement(nums);
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            long long Maxsum= 1LL*(i-PGE[i])*(NGE[i]-i)*nums[i];
            long long  Minsum= 1LL*(i-PSE[i])*(NSE[i]-i)*nums[i];
            sum+=Maxsum-Minsum;
        }

        return sum;
    }
};