class Solution {
public:
    
    void fun(int idx,vector<int>&cookies,int k,vector<int>&children,int &result,int n){
        if(idx==n){
            int maximum=*max_element(begin(children),end(children));
            result=min(result,maximum);
            return;
        }
        for(int i=0;i<k;i++){
           children[i]+=cookies[idx];
           fun(idx+1,cookies,k,children,result,n);
           children[i]-=cookies[idx];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        int result=INT_MAX;  vector<int>children(k,0);   // hr bachhe ke pass suru me 1 cookies hai
        fun(0,cookies,k,children,result,n);
        return result;

    }
};


//                         Start
//                      index = 0
//                     children = [0,0]

//                    Cookie = 8
//                  /             \
//          Child 0              Child 1
//       [8,0]                  [0,8]
//       index=1                index=1


//        Cookie =15              Cookie =15
//       /         \             /          \
//  [23,0]      [8,15]      [15,8]      [0,23]
//  index=2     index=2     index=2     index=2


//  Cookie=10   Cookie=10   Cookie=10   Cookie=10
//   /    \       /   \       /   \        /   \

// [33,0] [23,10]
//  max=33 max=23
