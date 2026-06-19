class Solution {
public:
    bool checkGoodInteger(int n) {
        int temp=n;int digitSum=0;int squareSum=0;
       while(temp>0){
           int digit=temp%10;
           digitSum+=digit;
           squareSum+=digit*digit;
           temp=temp/10;
       } 

        if(squareSum-digitSum>=50) return true;

        return false;
    }
};