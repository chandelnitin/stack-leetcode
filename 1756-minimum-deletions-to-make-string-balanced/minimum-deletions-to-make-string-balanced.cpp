class Solution {
public: // hme esi string bnani hai jha sabhi a left me or sbhi b right me ho jaise
// aaaabbb esi honi chaiye output string ab hme btani hai kitne deleteion krne hai minmum 
// ki out put string aaaabbbb esi ho.
// ab meri approch hai mai hr ch ko stack me dalunga jb bhi mera stack ka top a or ith ch 
// b hai ye condition shi . lekin jb bhi stack ka top b or ch a to ye glat hai kuki b ke bad a nhi aa . ya to mujhe a delete krna pdega ya b . hme isse matlab nhi hai ki kya delte krna pdega bs ye hai kuch delete krne pdega vrna order kharab ho jayega
    int minimumDeletions(string s) {
        stack<char>st; int count=0;
        for(auto &ch:s){
            if(!st.empty() && st.top()=='b' && ch=='a'){ // matlb ye order glt hai ya to b delete krna 
                count++;               // pdega ya a 
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        return count;
    }
};






// class Solution {
// public: //4 approach
//     int minimumDeletions(string s) {
//        int totalA=0;
//        for(auto &ch:s){
//           if(ch=='a'){
//             totalA++;
//           }
          
//        }  
//         int aCount=0;
//         int bCount=0;
//         int ans=totalA; // agr me sare a delete kr du
//        for(auto &ch:s){
//           if(ch=='a'){
//             aCount++;
//           }
//           else{
//             bCount++;
//           }

//           ans=min(ans,(totalA-aCount+bCount));

//        }

//        return ans;
//     }
// };