// class Solution {
// public: // TLE
//    int fun(int i,vector<int>& rating,vector<int> &temp){
//        if(temp.size()==3){
//           if(temp[0]<temp[1] && temp[1]<temp[2]) return 1;
//           if(temp[0]>temp[1] && temp[1]>temp[2]) return 1;
//           return 0;
//        }

//        if(i==rating.size()) return 0;
       
//         temp.push_back(rating[i]);
//        int take= fun(i+1,rating,temp);
//        temp.pop_back();
//        int notake= fun(i+1,rating,temp);

//        return take+notake;
//    }
//     int numTeams(vector<int>& rating) {
//         vector<int>temp; 
//         return fun(0,rating,temp);
//     }
// };
















// class Solution {
// public:
//    int fun(int i,vector<int>& rating,vector<int> &temp,map<pair<int,vector<int>>,int>&dp){
//        if(temp.size()==3){
//           if(temp[0]<temp[1] && temp[1]<temp[2]) return 1;
//           if(temp[0]>temp[1] && temp[1]>temp[2]) return 1;
//           return 0;
//        }

//        if(i==rating.size()) return 0;
//         if(dp.find({i,temp})!=dp.end()) return dp[{i,temp}];
//         temp.push_back(rating[i]);
//        int take= fun(i+1,rating,temp,dp);
//        temp.pop_back();
//        int notake= fun(i+1,rating,temp,dp);

//        return dp[{i,temp}]= take+notake;
//    }
//     int numTeams(vector<int>& rating) {
//         vector<int>temp; map<pair<int,vector<int>>,int>dp;
//         return fun(0,rating,temp,dp);
//     }
// };




































class Solution {
public:
    // mai hr jth element ko center manker uske left me smaller and uske right me greater check krung for incresing team and ecreasing team ke liye left me kitne greater hai or right me kitne smaller hai   
    int numTeams(vector<int>& rating) {
       int n=rating.size(); int ans=0;
       for(int j=0;j<n;j++){
         int leftsmaller=0;
         int leftgreater=0;
         int rightgreater=0;
         int rightsmaller=0;

         // left check;
         for(int i=0;i<j;i++){
            if(rating[i]<rating[j]){
                leftsmaller++;
            }
            else{
                leftgreater++;
            }
         }


         // right check

         for(int i=j+1;i<n;i++){
            if(rating[i]<rating[j]){
                rightsmaller++;
            }
            else{
                rightgreater++;
            }
         }

         ans+=leftsmaller*rightgreater;
         ans+= leftgreater*rightsmaller;
       }

       return ans;
    }
};
