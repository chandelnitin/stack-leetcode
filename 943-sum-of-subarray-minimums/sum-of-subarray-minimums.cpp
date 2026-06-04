class Solution {
public:
    vector<int> nextSmallerleft(vector<int>& arr){
         stack<int>st;
         vector<int>NSL;
         int i=0;
         int n=arr.size();
         while(i<n){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }


            if(st.empty()){
                NSL.push_back(-1);
            }
            else{
                NSL.push_back(st.top());
            }

            st.push(i);
            i++;
         }

         return NSL;
    }
  


    vector<int> nextSmallerRight(vector<int>& arr){
         stack<int>st;
         int n=arr.size();
         vector<int>NSR(n);
         int i=n-1;
         while(i>=0){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }


            if(st.empty()){
                NSR[i]=n;
            }
            else{
                NSR[i]=st.top();
            }

            st.push(i);
            i--;
         }

         return NSR;

    }

    
    int sumSubarrayMins(vector<int>& arr) {
        const vector<int>&NSL=nextSmallerleft(arr);
        const vector<int>&NSR=nextSmallerRight(arr);
        int long long mod= 1e9+7;
        int sum=0;
         for(int i=0;i<arr.size();i++){
               sum=(sum+ ((long long)(i-NSL[i])*(NSR[i]-i)%mod)*arr[i]%mod)%mod;
               
         }
        return sum;
    }
};