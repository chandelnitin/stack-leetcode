class Solution {
public: // n-x<=k ke matlab x>= n-k  
// |10-8| = 2 ✅
// |10-9| = 1 ✅
// |10-10| = 0 ✅
// |10-11| = 1 ✅
// |10-12| = 2 ✅
// |10-13| = 3 ❌
    int sumOfGoodIntegers(int n, int k) {
        int sum=0;
        for(int x=max(1,n-k) ;x<=n+k;x++){  // yh max(i,n-k) isliye liya kuki x ek
            if((x&n)==0){   // positive integer hona chhiye
                sum+=x;
            }
        }

        return sum;
    }
};