class Solution {
public:
    bool fun(vector<int>& arr, int idx,vector<bool>& visited){
        if(idx<0 || idx>=arr.size()) return false;
        if(arr[idx]==0) return true;
        if(visited[idx]==true) return false;
        visited[idx]=true;
        bool left =fun(arr,idx+arr[idx],visited);
       bool right =fun(arr,idx-arr[idx],visited);
       return left||right;
    }
    bool canReach(vector<int>& arr, int start) {
       vector<bool>visited(arr.size(),false);
       return fun(arr,start,visited); 
    }
};