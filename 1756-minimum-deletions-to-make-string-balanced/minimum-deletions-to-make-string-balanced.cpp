// class Solution {
// public: // hme esi string bnani hai jha sabhi a left me or sbhi b right me ho jaise
// // aaaabbb esi honi chaiye output string ab hme btani hai kitne deleteion krne hai minmum 
// // ki out put string aaaabbbb esi ho.
// // ab meri approch hai mai hr ch ko stack me dalunga jb bhi mera stack ka top a or ith ch 
// // b hai ye condition shi . lekin jb bhi stack ka top b or ch a to ye glat hai kuki b ke bad a nhi aa . ya to mujhe a delete krna pdega ya b . hme isse matlab nhi hai ki kya delte krna pdega bs ye hai kuch delete krne pdega vrna order kharab ho jayega
//     int minimumDeletions(string s) {
//         stack<char>st; int count=0;
//         for(auto &ch:s){
//             if(!st.empty() && st.top()=='b' && ch=='a'){ // matlb ye order glt hai ya to b delete krna 
//                 count++;               // pdega ya a 
//                 st.pop();
//             }
//             else{
//                 st.push(ch);
//             }
//         }

//         return count;
//     }
// };










class Solution { // sc o(n) tc o(n)
public: // hme esi string bnani hai jha sabhi a left me or sbhi b right me ho jaise
// aaaabbb esi honi chaiye output string ab hme btani hai kitne deleteion krne hai minmum 
// ki out put string aaaabbbb esi ho.
//meri approch hai mai hr ch pr khada hoker dhekunga ki left me kitne b hai or right me kitne a hai unko delete krna pdega kuki agr left me b hai to glat order ho jayega or agr left me sare a maintain krne hai right me sare a delete krne pdega jbhi to right me sare b honge. to mai kya krunga hr ch ke corsponding do array bnaounga or store kra lunga ki is ch ke left me kitn a hai or right me kitne b hai . or fir unko add krunga kuki mujhe sare lft ke b delete krne hai or right ke sare a . or jha bhi minimum anser mil jayega use store kra lunga
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>left_b(n);
        vector<int>right_a(n);
        int a=0;int b=0;
        for(int i=0;i<n;i++){
            left_b[i]=b;
            if(s[i]=='b'){
                b++;
            }
        }

        for(int i=n-1;i>=0;i--){
            right_a[i]=a;
            if(s[i]=='a'){
                a++;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,(left_b[i]+right_a[i]));
        }

        return ans;
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