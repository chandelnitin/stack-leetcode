class Solution {
public:
    vector<int> nextSmallerElemenent(vector<int>& arr) {
        stack<int>st; // maintaing decreasing stack of indexs
        int n=arr.size();
        vector<int>ans(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                ans[st.top()]=i; // arr[i] ke left me jitne bhi element arr[i] se bade hai unke liye arr[i] smaller element hoga isliye hmne index strore kiya . jisse un sbhi element ke index pr arr[i] dal ske
                st.pop();
            }
            
            st.push(i);
        }
        
        return ans;
    }

     

      vector<int> previousSmallerElement(vector<int>& arr) {
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



    int largestRectangleArea(vector<int>& heights) {
        vector<int>NSE= nextSmallerElemenent(heights);
        vector<int> PSE= previousSmallerElement(heights);

        int largestHistogram=0;
        for(int i=0;i<heights.size();i++){
            int retangle= (NSE[i]-PSE[i]-1)*heights[i];
            largestHistogram=max(largestHistogram,retangle);
        }

        return largestHistogram;
    }
};