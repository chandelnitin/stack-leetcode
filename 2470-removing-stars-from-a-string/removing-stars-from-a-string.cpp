// class Solution {
// public: //3 approach
//     string removeStars(string s) {
//         string ans=""; // ans sring as stack using
//         for(int i=0;i<s.size();i++){
//            if(!ans.empty() && s[i]=='*'){
//             ans.pop_back();
//            }
//            else {
//               ans.push_back(s[i]);
//            }
//         }

//         return ans;
//     }
// };







class Solution {
public: //3 approach  // Sc o(1)
    string removeStars(string s) {
        int j=0;
        for(auto &ch:s){
            if(ch=='*'){
                j--;
            }
            else{
                s[j++]=ch;
            }
        }
        s.resize(j);
        return s;
   
    }
};