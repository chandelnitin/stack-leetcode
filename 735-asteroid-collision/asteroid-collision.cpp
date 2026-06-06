class Solution {
public: // collsion hoga only agr stack ke top pr positive or arr[i] negative ho
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i=0;
        int n=asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            bool flag=true;
            while(!st.empty() && st.top()>0 && asteroids[i]<0 ){
                if(st.top()<abs(asteroids[i])){
                    st.pop(); 
                }
                else if(st.top()==abs(asteroids[i])){
                    st.pop();
                    flag=false;
                    break;
                }
                else{
                    flag=false;
                    break;
                }

            }
                if(flag) st.push(asteroids[i]);
        }

        
        vector<int>ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
        
    }
};