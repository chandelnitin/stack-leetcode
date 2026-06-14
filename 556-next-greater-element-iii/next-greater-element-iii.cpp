class Solution {
public:
    int nextGreaterElement(int x) {
        string s= to_string(x);
        int n=s.size();
        int pivot=-1;// vo index jha s[i]<s[i+1]
        for(int i=n-2;i>=0;i--){
            if(s[i]<s[i+1]){
                pivot=i;
                break;
            }
        }

        if(pivot==-1) return -1;
        for(int i=n-1;i>pivot;i--){ //us elemnt ko dhundo ji picot eleemnt se just bada
            if(s[i]>s[pivot]){
                swap(s[i],s[pivot]);
                break;
            }
        }
        // reverse 
        int start=pivot+1;
        int end=n-1;
        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;
        }

        long long ans= stoll(s);

        return (ans>INT_MAX)?-1:ans;
        

    }
};