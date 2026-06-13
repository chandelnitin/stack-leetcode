class Solution {
public: //3 approach
    string removeStars(string s) {
        string ans=""; // ans sring as stack using
        for(int i=0;i<s.size();i++){
           if(!ans.empty() && s[i]=='*'){
            ans.pop_back();
           }
           else {
              ans.push_back(s[i]);
           }
        }

        return ans;
    }
};