class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans=""; // using as a stack
        int count=0;
        for(int i=0;i<num.size();i++){
            while(!ans.empty() && count<k && ans.back()>num[i]){
                ans.pop_back();
                count++;
            }

            ans.push_back(num[i]);
        }
        
 // agr number alread chota ho jaise 12345 to back se remove . agr hmara count<k hai

        while(count<k){
            ans.pop_back();
            count++;
        }
               
        int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i);
        return (ans.size()==0)?"0":ans;
    }
};