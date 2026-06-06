// class Solution {
// public: // collsion hoga only agr stack ke top pr positive or arr[i] negative ho
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         int i=0;
//         int n=asteroids.size();
//         stack<int>st;
//         for(int i=0;i<n;i++){
//             bool flag=true;
//             while(!st.empty() && st.top()>0 && asteroids[i]<0 ){
//                 if(st.top()<abs(asteroids[i])){
//                     st.pop(); 
//                 }
//                 else if(st.top()==abs(asteroids[i])){
//                     st.pop();
//                     flag=false;
//                     break;
//                 }
//                 else{
//                     flag=false;
//                     break;
//                 }

//             }
//                 if(flag) st.push(asteroids[i]);
//         }

        
//         vector<int>ans(st.size());
//         for (int i = st.size() - 1; i >= 0; i--) {
//             ans[i] = st.top();
//             st.pop();
//         }
//         return ans;
        
//     }
// };













class Solution {  // same approch but clean
public: // collsion hoga only agr stack ke top pr positive or arr[i] negative ho
// mai ek sum lunga agr mera sum negative matlab stack.top<astroid[i] and posstive 
// stack.top()>astroid[i] and sum==0 stac.top()==astroid[i] and ab hmm stack use nhi kringe vector hi use krnege kuki vector me pop_back ki complexty o(1) hi hai
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        for(auto &a:asteroids){
            while(!ans.empty() && ans[ans.size()-1]>0 && a<0){
                int sum=a+ans[ans.size()-1];
                if(sum<0){
                    ans.pop_back();
                }
                else if(sum>0){
                    a=0;
                }
                else{ //sum=0
                    ans.pop_back();
                    a=0;
                }
            }

            if(a!=0) ans.push_back(a);
        }

        return ans;
    }
};