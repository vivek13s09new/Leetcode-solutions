class Solution {
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        for(int n: nums2){
            while(!st.empty() && st.top() < n){
                mp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }

        vector<int> ans;
        for(int n: nums1){
            ans.push_back(mp.count(n) ? mp[n] : -1);
        }
        return ans;        
    }
};