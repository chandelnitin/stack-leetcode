class Solution {
public:
    bool digitCount(string num) {
        map<int,int>freq;
        for(int i=0;i<num.size();i++){
            freq[num[i]-'0']++;
        }
        for(int i=0;i<num.size();i++){
            if(freq[i]!=num[i]-'0') return false;
        }

        return true;
    }
};