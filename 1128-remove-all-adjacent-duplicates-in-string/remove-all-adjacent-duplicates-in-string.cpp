class Solution {
public:
    string removeDuplicates(string s) {
        string ans=""; // am ans string as a stack use krkenge 

        for(int i=0;i<s.size();i++){
            bool flag=false;
            while(!ans.empty() && ans.back()==s[i]){
                ans.pop_back();
                flag=true;
            }

            if(!flag) ans.push_back(s[i]);
        }

        return ans;
    }
};