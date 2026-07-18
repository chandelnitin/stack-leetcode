class Solution {
public:
    int get_NcR(int n, int r)
{
    r = min(r, n - r);

    long long  ans = 1;

    for (int i = 1; i <= r; i++)
    {
        ans = ans * (n - i + 1);
        ans = ans / i;
    }

    return ans;
}
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        for(int r=0;r<=rowIndex;r++){
            ans.push_back(get_NcR(rowIndex,r));
        }

        return ans;
    }
};