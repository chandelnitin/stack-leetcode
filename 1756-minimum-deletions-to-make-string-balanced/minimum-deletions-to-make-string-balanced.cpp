class Solution {
public: //4 approach
    int minimumDeletions(string s) {
       int totalA=0;
       for(auto &ch:s){
          if(ch=='a'){
            totalA++;
          }
          
       }  
        int aCount=0;
        int bCount=0;
        int ans=totalA; // agr me sare a delete kr du
       for(auto &ch:s){
          if(ch=='a'){
            aCount++;
          }
          else{
            bCount++;
          }

          ans=min(ans,(totalA-aCount+bCount));

       }

       return ans;
    }
};