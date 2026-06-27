class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans={{}} ; // starting me empty subset hai
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        for(auto num:nums){
           int n=ans.size();
           for(int i=0;i<n;i++){
             vector<int>temp=ans[i];
             temp.push_back(num);
             if(st.find(temp)==st.end()){
                ans.push_back(temp);
             }
             st.insert(temp);
           }
        }
        
        return ans;
    }
};