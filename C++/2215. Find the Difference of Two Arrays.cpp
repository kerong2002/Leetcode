class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        set<int> n1;
        set<int> n2;
        for(int x=0;x<nums1.size();x++){
            n1.insert(nums1[x]);
        }
        for(int x=0;x<nums2.size();x++){
            n2.insert(nums2[x]);
        }

        for(set<int>::iterator it = n1.begin();it!=n1.end();it++){
            if(n2.find((*it)) == n2.end()){
                ans[0].push_back((*it));
            }
        }

        for(set<int>::iterator it = n2.begin();it!=n2.end();it++){
            if(n1.find((*it)) == n1.end()){
                ans[1].push_back((*it));
            }
        }
        return ans;
    }
};